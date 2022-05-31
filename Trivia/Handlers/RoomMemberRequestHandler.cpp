#include "RoomMemberRequestHandler.h"
#include "../Serializing/JsonResponsePacketSerializer.h"


bool RoomMemberRequestHandler::isRequestRelevant(RequestInfo req) {
	return req.buffer[0] >= GET_ROOMS_CODE && req.buffer[0] <= LEAVE_ROOM_CODE;
}

RequestResult RoomMemberRequestHandler::handleRequest(RequestInfo req) {
	if (req.buffer[0] == GET_ROOMS_CODE)
		return getRoomState();
	else if (req.buffer[0] == LEAVE_ROOM_CODE)
		return leaveRoom();
	
	return { JsonResponsePacketSerializer::serializeResponse(ErrorResponse{"Wrong message code!"}), this };
}

RequestResult RoomMemberRequestHandler::leaveRoom() {
	LeaveRoomResponse resp{ m_roomManager.getRoomById(m_roomId).removeUser(m_user) };
	return { JsonResponsePacketSerializer::serializeResponse(resp), m_handlerFactory.createMenuRequestHandler(m_user.m_username) };
}
