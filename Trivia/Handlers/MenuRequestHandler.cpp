#include "../Handlers/MenuRequestHandler.h"
#include "../Serializing/JsonResponsePacketSerializer.h"
#include "../Serializing/JsonRequestPacketDeserializer.h"

#define NULL_ID 0

MenuRequestHandler::MenuRequestHandler(const std::string& username, RoomManager& roomMngr, StatisticsManager& statsMngr, RequestHandlerFactory& fact) :
    m_username(username), m_roomManager(roomMngr), m_statisticsManager(statsMngr), m_handlerFactory(fact) {}

bool MenuRequestHandler::isRequestRelevant(RequestInfo req) {
    int code = (unsigned char) req.buffer[0];
    return code >= GET_ROOMS_CODE && code <= PERSONAL_STATS_CODE;
}

RequestResult MenuRequestHandler::handleRequest(RequestInfo req) {
    switch ((unsigned char)req.buffer[0]) {
    case GET_ROOMS_CODE:
        return getRooms(req.buffer);
        break;
    case GET_PLAYERS_CODE:
        return getPlayersInRoom(req.buffer);
        break;
    case JOIN_ROOM_CODE:
        return joinRoom(req.buffer);
        break;
    case CREATE_ROOM_CODE:
        return createRoom(req.buffer);
        break;
    case HIGH_SCORE_CODE:
        return getHighScore(req.buffer);
        break;
    case PERSONAL_STATS_CODE:
        return getStats(req.buffer);
        break;
    default:
        throw std::exception("Invalid code!");
    }
}

std::string MenuRequestHandler::getUsername() const
{
    return m_username;
}

RequestResult MenuRequestHandler::getRooms(const std::string& buffer) {
    GetRoomsResponse resp{ true, m_roomManager.getRooms() };
    return { JsonResponsePacketSerializer::serializeResponse(resp), this };
}

RequestResult MenuRequestHandler::getPlayersInRoom(const std::string& buffer) {
    GetPlayersInRoomRequest request = JsonRequestPacketDeserializer::deserializeGetPlayersInRoomRequest(buffer);
    GetPlayersInRoomResponse resp;
    
    try {
        std::vector<LoggedUser> users;
        users = m_roomManager.getRoomById(request.roomId).getAllUsers();
        for (LoggedUser user : users)
            resp.players.push_back(user.m_username);
    }
    catch (const std::exception& e) {
        ErrorResponse errorResp{ e.what() };
        return { JsonResponsePacketSerializer::serializeResponse(errorResp), this };
    }
    return { JsonResponsePacketSerializer::serializeResponse(resp), this };
}

RequestResult MenuRequestHandler::joinRoom(const std::string& buffer) {
    JoinRoomRequest request = JsonRequestPacketDeserializer::deserializeJoinRoomRequest(buffer);
    m_roomManager.getRoomById(request.roomId).addUser({ m_username });
    JoinRoomResponse resp{ true };
    return { JsonResponsePacketSerializer::serializeResponse(resp), m_handlerFactory.createRoomMemberRequestHandler(m_username, request.roomId)};
}

RequestResult MenuRequestHandler::createRoom(const std::string& buffer) {
    CreateRoomRequest request = JsonRequestPacketDeserializer::deserializeCreateRoomRequest(buffer);
    RoomData roomData{ NULL_ID, request.roomName, request.maxUsers, request.questionCount, request.answerTimeout, false };
    unsigned int roomId = m_roomManager.createRoom({ m_username }, roomData);
    CreateRoomResponse resp{ true };
    return { JsonResponsePacketSerializer::serializeResponse(resp), m_handlerFactory.createRoomAdminRequestHandler(m_username, roomId) };
}

RequestResult MenuRequestHandler::getHighScore(const std::string& buffer) {
    GetHighScoreResponse resp{ true, m_statisticsManager.getHighScore() };
    return { JsonResponsePacketSerializer::serializeResponse(resp), this };
}

RequestResult MenuRequestHandler::getStats(const std::string& buffer) {
    GetPersonalStatsResponse resp{true, m_statisticsManager.getUserStatistics(m_username) };
    return { JsonResponsePacketSerializer::serializeResponse(resp), this };
}