#include "RoomAdminRequestHandler.h"
#include "../Serializing/JsonResponsePacketSerializer.h"
#include "../Serializing/JsonRequestPacketDeserializer.h"

RoomAdminRequestHandler::RoomAdminRequestHandler(unsigned int roomId, LoggedUser user, RoomManager& roomManager, RequestHandlerFactory& fact) :
	RoomHandler(roomId, user, roomManager, fact) {}

bool RoomAdminRequestHandler::isRequestRelevant(RequestInfo req) const {
	return req.buffer[0] >= CLOSE_ROOM_CODE && req.buffer[0] <= GET_ROOM_STATE_CODE;
}

RequestResult RoomAdminRequestHandler::handleRequest(RequestInfo req) {
	if (req.buffer(0) == CLOSE_ROOM_CODE)
		return closeRoom(req);
	if (req.buffer[0] == START_GAME_CODE)
		return startGame(req);
	if (req.buffer[0] == GET_ROOM_STATE_CODE)
		return getRoomState(req);
	
	return { JsonResponsePacketSerializer::serializeResponse(ErrorResponse{"Wrong message code!"}), this };
}

RequestResult RoomAdminRequestHandler::closeRoom() {
	sendToUsers({ JsonResponsePacketSerializer::serializeResponse(LeaveRoomResponse{true}), nullptr});

	CloseRoomResponse resp{ m_roomManager.deleteRoom(m_roomId) };
	return { JsonResponsePacketSerializer::serializeResponse(resp), this };
}

RequestResult RoomAdminRequestHandler::startGame() {
	sendToUsers({ JsonResponsePacketSerializer::serializeResponse(StartGameResponse{true}), nullptr });

	StartGameResponse resp{ true };
	return { JsonResponsePacketSerializer::serializeResponse(resp), this };
}

void sendToUsers(RequestResult res) {
	for (LoggedUser user : m_roomManager.getRoomById(m_roomId).getAllUsers()) {
		m_handlerFactory.getCommunicator()->getClients();
	}
}