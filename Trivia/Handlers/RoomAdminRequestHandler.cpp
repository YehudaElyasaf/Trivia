#include "RoomAdminRequestHandler.h"
#include "../Serializing/JsonResponsePacketSerializer.h"
#include "../Serializing/JsonRequestPacketDeserializer.h"

RoomAdminRequestHandler::RoomAdminRequestHandler(unsigned int roomId, LoggedUser user, RoomManager& roomManager, RequestHandlerFactory& fact) :
	RoomHandler(roomId, user, roomManager, fact) {}

bool RoomAdminRequestHandler::isRequestRelevant(RequestInfo req) const {
	return req.buffer[0] >= CLOSE_ROOM_CODE && req.buffer[0] <= GET_ROOM_STATE_CODE;
}

RequestResult RoomAdminRequestHandler::handleRequest(RequestInfo req) {
	if (req.buffer[0] == CLOSE_ROOM_CODE)
		return closeRoom();
	if (req.buffer[0] == START_GAME_CODE)
		return startGame();
	if (req.buffer[0] == GET_ROOM_STATE_CODE)
		return getRoomState();
	
	return { JsonResponsePacketSerializer::serializeResponse(ErrorResponse{"Wrong message code!"}), this };
}

RequestResult RoomAdminRequestHandler::closeRoom() {
	sendToUsersInRoom({ JsonResponsePacketSerializer::serializeResponse(LeaveRoomResponse{true}), nullptr});

	CloseRoomResponse resp{ m_roomManager.deleteRoom(m_roomId) };
	return { JsonResponsePacketSerializer::serializeResponse(resp), this };
}

RequestResult RoomAdminRequestHandler::startGame() {
	sendToUsersInRoom({ JsonResponsePacketSerializer::serializeResponse(StartGameResponse{true}), nullptr });

	StartGameResponse resp{ true };
	return { JsonResponsePacketSerializer::serializeResponse(resp), this };
}

void RoomAdminRequestHandler::sendToUsersInRoom(RequestResult req) {
	for (LoggedUser user : m_roomManager.getRoomById(m_roomId).getAllUsers()) {
		m_handlerFactory.getCommunicator()->getClients();
	}
}