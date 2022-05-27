#pragma once
#include <IRequestHandler.h>
#include <RoomManager.h>
#include <RequestHandlerFactory.h>

class RoomAdminRequestHandler : public IRequestHandler {
public:
	bool isRequestRelevant(RequestInfo req) const override;
	RequestResult handleRequest(RequestInfo req) override;

private:
	Room m_room;
	LoggedUser m_user;
	RoomManager& m_roomManager;
	RequestHandlerFactory& m_handlerFactory;

	RequestResult closeRoom(RequestInfo req);
	RequestResult startGame(RequestInfo req);
	RequestResult getRoomState(RequestInfo req);
};