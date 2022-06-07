#pragma once
#include "IRequestHandler.h"
#include <RoomManager.h>
#include "RequestHandlerFactory.h"

class GameRequestHandler : public IRequestHandler {
public:
	GameRequestHandler(unsigned int roomId, LoggedUser user, RoomManager& roomManager, RequestHandlerFactory& fact);
	bool isRequestRelevant(struct RequestInfo req) override;
	RequestResult handleRequest(struct RequestInfo req) override;
	std::string getUsername() const override;

private:
	unsigned int roomId;
	LoggedUser m_user;
	RoomManager& m_roomManager;
	RequestHandlerFactory& m_handlerFactory;
};