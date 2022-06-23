#include "RoomAdminRequestHandler.h"
#include "RoomMemberRequestHandler.h"
#include "../Serializing/JsonResponsePacketSerializer.h"
#include "../Serializing/JsonRequestPacketDeserializer.h"
#include "../Communication/Helper.h"

RoomAdminRequestHandler::RoomAdminRequestHandler(const unsigned int roomId, const LoggedUser& user, RoomManager& roomManager, GameManager& gameManager,
	RequestHandlerFactory& fact) : m_roomId(roomId), m_user(user), m_roomManager(roomManager), m_handlerFactory(fact), m_gameManager(gameManager) {}

bool RoomAdminRequestHandler::isRequestRelevant(RequestInfo req) {
	return req.buffer[0] >= CLOSE_ROOM_CODE && req.buffer[0] <= GET_ROOM_STATE_CODE;
}

RequestResult RoomAdminRequestHandler::handleRequest(RequestInfo req) {
	if (req.buffer[0] == CLOSE_ROOM_CODE)
		return closeRoom();
	if (req.buffer[0] == START_GAME_CODE)
		return startGame();
	if (req.buffer[0] == GET_ROOM_STATE_CODE)
		return getRoomState(m_roomManager, m_roomId, this, m_handlerFactory);

	return { JsonResponsePacketSerializer::serializeResponse(ErrorResponse{"Wrong message code!"}), this };
}

std::string RoomAdminRequestHandler::getUsername() const {
	return m_user.m_username;
}

RequestResult RoomAdminRequestHandler::closeRoom() {
	sendToUsersInRoom({ JsonResponsePacketSerializer::serializeResponse(LeaveRoomResponse{true}),
					  nullptr }, CLOSE_ROOM_CODE);

	CloseRoomResponse resp{ m_roomManager.deleteRoom(m_roomId) };
	return { JsonResponsePacketSerializer::serializeResponse(resp), m_handlerFactory.createMenuRequestHandler(m_user.m_username) };
}

RequestResult RoomAdminRequestHandler::startGame() {
	Game game = m_gameManager.createGame(m_roomManager.getRoomById(m_roomId));
	sendToUsersInRoom({ JsonResponsePacketSerializer::serializeResponse(StartGameResponse{true}), m_handlerFactory.createGameRequestHandler("", m_roomId, game) }, START_GAME_CODE);

	StartGameResponse resp{ true };
	return { JsonResponsePacketSerializer::serializeResponse(resp), m_handlerFactory.createGameRequestHandler(m_user.m_username, m_roomId, game) };
}

void RoomAdminRequestHandler::sendToUsersInRoom(const RequestResult& req, const int msgType) {
	m_handlerFactory.getCommunicator()->clientsMutex.lock();

	for (auto client : m_handlerFactory.getCommunicator()->getClients()) {
		for (LoggedUser user : m_roomManager.getRoomById(m_roomId).getAllUsers()) {
			if (user == m_user)
				continue;
			try {
				if (user.m_username == ((RoomMemberRequestHandler*)client.second)->getUsername()) {
					Helper::sendData(client.first, req.response);
					delete m_handlerFactory.getCommunicator()->getClients()[client.first];
					if (msgType == CLOSE_ROOM_CODE)
						m_handlerFactory.getCommunicator()->getClients()[client.first] = m_handlerFactory.createMenuRequestHandler(user.m_username);
					else if (msgType == START_GAME_CODE) {
						m_handlerFactory.getCommunicator()->getClients()[client.first] = m_handlerFactory.createGameRequestHandler(user.m_username, m_roomId, ((GameRequestHandler*)req.newHandler)->getGame());
						delete req.newHandler;
					}
				}
			}
			catch (const NoUsernameException& e) {
				//do nothing
				// it means the client is not logged in, because it doesnt have getUsername function
			}

		}
	}
	
	m_handlerFactory.getCommunicator()->clientsMutex.unlock();
}