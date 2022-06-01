#pragma once
#include "RoomHandler.h"
#include "../Room/Room.h"
#include "../Handlers/RequestHandlerFactory.h"


class RoomMemberRequestHandler : public IRequestHandler {
public:
	RoomMemberRequestHandler(const unsigned int roomId, const LoggedUser user, RoomManager& roomManager, RequestHandlerFactory& fact);
	bool isRequestRelevant(struct RequestInfo req) override;
	RequestResult handleRequest(struct RequestInfo req) override;
	std::string getUsername() const;

private:
	unsigned int m_roomId;
	LoggedUser m_user;
	RoomManager& m_roomManager;
	RequestHandlerFactory& m_handlerFactory;

	RequestResult leaveRoom();
};

