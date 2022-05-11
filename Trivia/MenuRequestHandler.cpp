#include "MenuRequestHandler.h"
#include "JsonResponsePacketSerializer.h"
#include "JsonRequestPacketDeserializer.h"

#define NULL_ID 0

MenuRequestHandler::MenuRequestHandler(const std::string& username, RoomManager& roomMngr, StatisticsManager& statsMngr) :
    m_username(username), m_RoomManager(roomMngr), m_statisticsManager(statsMngr) {}

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
    }
}

RequestResult MenuRequestHandler::getRooms(const std::string& buffer) {
    CreateRoomRequest request = JsonRequestPacketDeserializer::deserializeCreateRoomRequest(buffer);
    RoomData data{ NULL_ID, request.roomName, request.maxUsers, request.questionCount, request.answerTimeout, false };
    m_roomManager.createRoom({m_username}, data);
}

RequestResult MenuRequestHandler::getPlayersInRoom(const std::string& buffer) {
    GetPlayersInRoomRequest request = JsonRequestPacketDeserializer::deserializeGetPlayersInRoomRequest(buffer);
    GetPlayersInRoomResponse resp;
    resp.players = m_roomManager.getRoomById(request.roomId).getAllUsers();
    return { JsonResponsePacketSerializer::serializeResponse(resp), this };
}

RequestResult MenuRequestHandler::joinRoom(const std::string& buffer) {
    JoinRoomRequest request = JsonRequestPacketDeserializer::deserializeJoinRoomRequest(buffer);
    m_roomManager.getRoomById(request.roomId).addUser({ m_username });
    JoinRoomResponse resp{ true };
    return { JsonResponsePacketSerializer::serializeResponse(resp), this };
}

RequestResult MenuRequestHandler::createRoom(const std::string& buffer) {
    CreateRoomRequest request = JsonRequestPacketDeserializer::deserializeCreateRoomRequest(buffer);
    m_roomManager.createRoom({ m_username }, { NULL_ID, request.roomName, request.maxUsers, request.questionCount, request.answerTimeout, false });
    CreateRoomResponse resp{ true };
    return { JsonResponsePacketSerializer::serializeResponse(resp), this };
}

RequestResult MenuRequestHandler::getHighScore(const std::string& buffer) {
    GetHighScoreResponse resp{ true, m_statisticsManager.getHighScore() };
    return { JsonResponsePacketSerializer::serializeResponse(resp), this };
}

RequestResult MenuRequestHandler::getStats(const std::string& buffer) {
    GetPersonalStatsResponse resp{true, m_statisticsManager.getUserStatistics(m_username) };
    return { JsonResponsePacketSerializer::serializeResponse(resp), this }
}