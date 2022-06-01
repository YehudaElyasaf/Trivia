#pragma once
#include "IRequestHandler.h"
#include "../Room/RoomManager.h"
#include "RequestHandlerFactory.h"

class RoomHandler : public IRequestHandler {
public:
	RoomHandler(unsigned int roomId, LoggedUser user, RoomManager& roomManager, RequestHandlerFactory& fact);
	virtual bool isRequestRelevant(RequestInfo req) const = 0;
	virtual RequestResult handleRequest(RequestInfo req) = 0;

protected:
	LoggedUser m_user;
	unsigned int m_roomId;
	RoomManager& m_roomManager;
	RequestHandlerFactory& m_handlerFactory;

	RequestResult getRoomState();
};