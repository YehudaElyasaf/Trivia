#include "RoomAdminRequestHandler.h"
#include "RoomMemberRequestHandler.h"
#include "../Serializing/JsonResponsePacketSerializer.h"
#include "../Serializing/JsonRequestPacketDeserializer.h"
#include "../Communication/Helper.h"

RoomAdminRequestHandler::RoomAdminRequestHandler(unsigned int roomId, LoggedUser user, RoomManager& roomManager, RequestHandlerFactory& fact) :
	m_roomId(roomId), m_user(user), m_roomManager(roomManager), m_handlerFactory(fact) {}

bool RoomAdminRequestHandler::isRequestRelevant(RequestInfo req) {
	return req.buffer[0] >= CLOSE_ROOM_CODE && req.buffer[0] <= GET_ROOM_STATE_CODE;
}

RequestResult RoomAdminRequestHandler::handleRequest(RequestInfo req) {
	if (req.buffer[0] == CLOSE_ROOM_CODE)
		return closeRoom();
	if (req.buffer[0] == START_GAME_CODE)
		return startGame();
	if (req.buffer[0] == GET_ROOM_STATE_CODE)
		return getRoomState(m_roomManager, m_roomId, this);
	
	return { JsonResponsePacketSerializer::serializeResponse(ErrorResponse{"Wrong message code!"}), this };
}

RequestResult RoomAdminRequestHandler::closeRoom() {
	sendToUsersInRoom({ JsonResponsePacketSerializer::serializeResponse(LeaveRoomResponse{true}), nullptr});

	CloseRoomResponse resp{ m_roomManager.deleteRoom(m_roomId) };
	return { JsonResponsePacketSerializer::serializeResponse(resp), m_handlerFactory.createMenuRequestHandler(m_user.m_username)};
}

RequestResult RoomAdminRequestHandler::startGame() {
	sendToUsersInRoom({ JsonResponsePacketSerializer::serializeResponse(StartGameResponse{true}), nullptr });

	StartGameResponse resp{ true };
	return { JsonResponsePacketSerializer::serializeResponse(resp), this };
}

void RoomAdminRequestHandler::sendToUsersInRoom(RequestResult req) {
	for (auto client : m_handlerFactory.getCommunicator()->getClients()) {
		for (LoggedUser user : m_roomManager.getRoomById(m_roomId).getAllUsers()) {
			try {
				if (user.m_username == ((RoomMemberRequestHandler*)client.second)->getUsername())
					Helper::sendData(client.first, req.response);
			}
			catch (...) {
				// it means the client is not in a room, because it doesnt have m_user.m_username
			}
		}
	}
}