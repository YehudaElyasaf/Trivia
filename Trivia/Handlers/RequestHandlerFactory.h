#pragma once
#include "../Databases/IDatabase.h"
#include "../Handlers/LoginRequestHandler.h"
#include "../Handlers/MenuRequestHandler.h"
#include "../Login/LoginManager.h"
#include "../Communication/Communicator.h"

class LoginRequestHandler;
class Communicator;

class RequestHandlerFactory {
public:
	RequestHandlerFactory(IDatabase* database);
	
	LoginRequestHandler* createLoginRequestHandler();
	MenuRequestHandler* createMenuRequestHandler(std::string& username);
	
	LoginManager& getLoginManager();
	StatisticsManager& getStatisticsManager();
	RoomManager& getRoomManager();

	void setCommunicator(Communicator* communicator);
	Communicator* getCommunicator();

private:
	LoginManager m_loginManager;
	RoomManager m_roomManager;
	StatisticsManager m_statisticsManager;
	IDatabase* m_database;
	Communicator* m_communicator;
};

