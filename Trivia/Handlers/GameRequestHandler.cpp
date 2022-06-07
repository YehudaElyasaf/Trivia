#include <GameReuqestHandler.h>
#include "GameRequestHandler.h"

GameRequestHandler::GameRequestHandler(unsigned int roomId, LoggedUser user, RoomManager& roomManager, RequestHandlerFactory& fact):
	m_roomId(roomId), m_user(user), m_roomManager(RoomManager), m_handlerFactory(fact) {}

bool GameRequestHandler::isRequestRelevant(RequestInfo req) {
	return false;
}

RequestResult GameRequestHandler::handleRequest(RequestInfo req) {
	return RequestResult();
}

std::string GameRequestHandler::getUsername() const {
	return m_user.m_username;
}

