#pragma once
#include "IRequestHandler.h"
#include <RoomManager.h>
#include "RequestHandlerFactory.h"
#include <Game.h>

class GameRequestHandler : public IRequestHandler {
public:
	GameRequestHandler(unsigned int roomId, LoggedUser user, RoomManager& roomManager, RequestHandlerFactory& fact, Game& game);
	bool isRequestRelevant(struct RequestInfo req) override;
	RequestResult handleRequest(struct RequestInfo req) override;
	std::string getUsername() const override;

private:
	unsigned int m_roomId;
	LoggedUser m_user;
	RoomManager& m_roomManager;
	RequestHandlerFactory& m_handlerFactory;
	Game& m_game;

	RequestResult getResults();
	RequestResult submitAns(RequestInfo req);
	RequestResult questionResponse();
	RequestResult leaveGame();
};