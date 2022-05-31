#pragma once
#include "RoomHandler.h"
#include "../Room/Room.h"
#include "../Handlers/RequestHandlerFactory.h"


class RoomMemberRequestHandler : public RoomHandler {
public:
	bool isRequestRelevant(struct RequestInfo req) override;
	RequestResult handleRequest(struct RequestInfo req) override;

private:
	RequestResult leaveRoom();
};

