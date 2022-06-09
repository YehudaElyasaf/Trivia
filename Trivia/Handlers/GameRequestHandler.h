#pragma once
#include "IRequestHandler.h"
#include "RequestHandlerFactory.h"

class RequestHandlerFactory;
class Game;

class GameRequestHandler : public IRequestHandler {
public:
	GameRequestHandler(unsigned int roomId, LoggedUser user, RoomManager& roomManager, RequestHandlerFactory& fact, Game& game);
	bool isRequestRelevant(struct RequestInfo req) override;
	RequestResult handleRequest(struct RequestInfo req) override;
	std::string getUsername() const override;
	
	Game& getGame();
	unsigned int getRoomId() const;

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