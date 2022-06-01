#include "RoomMemberRequestHandler.h"
#include "../Serializing/JsonResponsePacketSerializer.h"


RoomMemberRequestHandler::RoomMemberRequestHandler(const unsigned int roomId, const LoggedUser user, RoomManager& roomManager, RequestHandlerFactory& fact) :
	m_roomId(roomId), m_user(user), m_roomManager(roomManager), m_handlerFactory(fact) {}

bool RoomMemberRequestHandler::isRequestRelevant(RequestInfo req) {
	return req.buffer[0] >= GET_ROOM_STATE_CODE && req.buffer[0] <= LEAVE_ROOM_CODE;
}

RequestResult RoomMemberRequestHandler::handleRequest(RequestInfo req) {
	if (req.buffer[0] == GET_ROOM_STATE_CODE)
		return getRoomState(m_roomManager, m_roomId, this);
	if (req.buffer[0] == LEAVE_ROOM_CODE)
		return leaveRoom();

	return { JsonResponsePacketSerializer::serializeResponse(ErrorResponse{"Wrong message code!"}), this };
}

std::string RoomMemberRequestHandler::getUsername() const {
	return m_user.m_username;
}

RequestResult RoomMemberRequestHandler::leaveRoom() {
	LeaveRoomResponse resp{ m_roomManager.getRoomById(m_roomId).removeUser(m_user) };
	return { JsonResponsePacketSerializer::serializeResponse(resp), m_handlerFactory.createMenuRequestHandler(m_user.m_username) };
}
