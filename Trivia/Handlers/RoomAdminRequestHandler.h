#pragma once
#include "RoomHandler.h"

class RequestHandlerFactory;

class RoomAdminRequestHandler : public IRequestHandler {
public:
	RoomAdminRequestHandler(unsigned int roomId, LoggedUser user, RoomManager& roomManager, RequestHandlerFactory& fact);
	bool isRequestRelevant(RequestInfo req) override;
	RequestResult handleRequest(RequestInfo req) override;

	RequestResult closeRoom();
	std::string getUsername() const override;

private:
	RequestResult startGame();
	void sendToUsersInRoom(RequestResult req, int msgType);

	unsigned int m_roomId;
	LoggedUser m_user;
	RoomManager& m_roomManager;
	RequestHandlerFactory& m_handlerFactory;
};