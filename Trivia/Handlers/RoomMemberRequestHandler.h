#pragma once
#include "IRequestHandler.h"
#include "../Room/Room.h"
#include "../Handlers/RequestHandlerFactory.h"


class RoomMemberRequestHandler : public IRequestHandler {
public:
	bool isRequestRelevant(struct RequestInfo req) override;
	RequestResult handleRequest(struct RequestInfo req) override;

private:
	Room m_room;
	LoggedUser m_user;
	RoomManager& m_roomManager;
	RequestHandlerFactory& m_handlerFactory;
};

