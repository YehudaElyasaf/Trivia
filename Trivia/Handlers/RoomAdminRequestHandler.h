#pragma once
#include "RequestHandlerFactory.h"

class RequestHandlerFactory;
class GameManager;
class RoomManager;

class RoomAdminRequestHandler : public IRequestHandler {
public:
	RoomAdminRequestHandler(const unsigned int roomId, const LoggedUser& user, RoomManager& roomManager, GameManager& gameManager, RequestHandlerFactory& fact);
	bool isRequestRelevant(RequestInfo req) override;
	RequestResult handleRequest(RequestInfo req) override;
	HANDLER_TYPE getType() const override;

	RequestResult closeRoom();
	std::string getUsername() const override;

private:
	RequestResult startGame();
	void changeHandlerOfUsersInRoom(const RequestResult& req, const int msgType);

	unsigned int m_roomId;
	LoggedUser m_user;
	RoomManager& m_roomManager;
	GameManager& m_gameManager;
	RequestHandlerFactory& m_handlerFactory;
};