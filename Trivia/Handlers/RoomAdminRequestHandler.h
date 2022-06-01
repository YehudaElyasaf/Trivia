#pragma once
#include "RoomHandler.h"

class RoomAdminRequestHandler : public RoomHandler {
public:
	RoomAdminRequestHandler(unsigned int roomId, LoggedUser user, RoomManager& roomManager, RequestHandlerFactory& fact);
	bool isRequestRelevant(RequestInfo req) const override;
	RequestResult handleRequest(RequestInfo req) override;

private:
	RequestResult closeRoom();
	RequestResult startGame();
	void sendToUsersInRoom(RequestResult req);
};