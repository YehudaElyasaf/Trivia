#pragma once
#include "IRequestHandler.h"
#include "../Room/RoomManager.h"
#include "RequestHandlerFactory.h"

class RoomHandler : public IRequestHandler {
private:
	RequestResult getRoomState();
	Room m_room;
	LoggedUser m_user;
	unsigned int m_roomId;
	RoomManager& m_roomManager;
	RequestHandlerFactory& m_handlerFactory;
};