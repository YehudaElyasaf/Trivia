#include "RoomMemberRequestHandler.h"

bool RoomMemberRequestHandler::isRequestRelevant(RequestInfo req) {
	return req.buffer[0] >= CLOSE_ROOM_CODE && req.buffer[0] <= GET_ROOM_STATE_CODE;
}

RequestResult RoomMemberRequestHandler::handleRequest(RequestInfo req) {
	return RequestResult();
}
