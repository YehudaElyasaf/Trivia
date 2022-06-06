#pragma once
#include "../Handlers/IRequestHandler.h"
#include "../Handlers/RequestHandlerFactory.h"
#include "../Databases/StatisticsManager.h"
#include "../Room/RoomManager.h"
#include "../Defines/msgCodes.h"

class RequestHandlerFactory;

class MenuRequestHandler : public IRequestHandler {
public:
	MenuRequestHandler(const std::string& username, RoomManager& roomMngr, StatisticsManager& statsMngr, RequestHandlerFactory& fact);
	bool isRequestRelevant(struct RequestInfo req) override;
	RequestResult handleRequest(struct RequestInfo req) override;
	std::string getUsername() const override;

private:
	StatisticsManager& m_statisticsManager;
	RoomManager& m_roomManager;
	RequestHandlerFactory& m_handlerFactory;
	std::string m_username;

	// handle request based on type and return result
	RequestResult getRooms(const std::string& buffer);
	RequestResult getPlayersInRoom(const std::string& buffer);
	RequestResult joinRoom(const std::string& buffer);
	RequestResult createRoom(const std::string& buffer);
	RequestResult getHighScore(const std::string& buffer);
	RequestResult getStats(const std::string& buffer);
};