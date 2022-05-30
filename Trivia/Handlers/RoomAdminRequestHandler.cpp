#include "RoomAdminRequestHandler.h"
#include "../Serializing/JsonResponsePacketSerializer.h"
#include "../Serializing/JsonRequestPacketDeserializer.h"

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

RequestResult RoomAdminRequestHandler::closeRoom(RequestInfo req) {
	CloseRoomRequest request = JsonRequestPacketDeserializer::deserializeCloseRoomRequest(req);

	CloseRoomResponse resp{ m_roomManager.deleteRoom(request.roomId) };
	return { JsonResponsePacketSerializer::serializeResponse(resp), this };
}

RequestResult RoomAdminRequestHandler::startGame(RequestInfo req) {
	StartGameRequest request = JsonRequestPacketDeserializer::deserializeStartGameRequest(req);

	StartGameResponse resp{ true };
	return { JsonResponsePacketSerializer::serializeResponse(resp), this };
}
