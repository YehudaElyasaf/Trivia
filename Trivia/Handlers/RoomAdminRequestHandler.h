#pragma once
#include "RoomHandler.h"

class RoomAdminRequestHandler : public RoomHandler {
public:
	bool isRequestRelevant(RequestInfo req) const override;
	RequestResult handleRequest(RequestInfo req) override;

private:
	RequestResult closeRoom(RequestInfo req);
	RequestResult startGame(RequestInfo req);
};