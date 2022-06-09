#pragma once
#include "../Databases/IDatabase.h"
#include "../Databases/StatisticsManager.h"
#include "../Handlers/LoginRequestHandler.h"
#include "../Handlers/MenuRequestHandler.h"
#include "../Handlers/RoomAdminRequestHandler.h"
#include "../Handlers/RoomMemberRequestHandler.h"
#include "../Handlers/GameRequestHandler.h"
#include "../Login/LoginManager.h"
#include "../Game/GameManager.h"
#include "../Communication/Communicator.h"
#include "../Game/Game.h"

class LoginRequestHandler;
class RoomAdminRequestHandler;
class MenuRequestHandler;
class RoomMemberRequestHandler;
class GameRequestHandler;

class Communicator;
class StatisticsManager;

class RequestHandlerFactory {
public:
	RequestHandlerFactory(IDatabase* database);
	
	LoginRequestHandler* createLoginRequestHandler();
	MenuRequestHandler* createMenuRequestHandler(const std::string& username);
	RoomAdminRequestHandler* createRoomAdminRequestHandler(const std::string& username, const unsigned int roomId);
	RoomMemberRequestHandler* createRoomMemberRequestHandler(const std::string& username, const unsigned int roomId);
	GameRequestHandler* createGameRequestHandler(const std::string& username, const unsigned int roomId, Game& game);
	
	LoginManager& getLoginManager();
	StatisticsManager& getStatisticsManager();
	RoomManager& getRoomManager();

	void setCommunicator(Communicator* communicator);
	Communicator* getCommunicator();

private:
	LoginManager m_loginManager;
	RoomManager m_roomManager;
	GameManager m_gameManager;
	StatisticsManager m_statisticsManager;
	IDatabase* m_database;
	Communicator* m_communicator;
};

