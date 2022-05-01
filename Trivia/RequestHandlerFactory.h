#pragma once
#include "IDatabase.h"
#include "LoginRequestHandler.h"

class RequestHandlerFactory {
public:
	RequestHandlerFactory(IDatabase* database);
	LoginRequestHandler* createLoginRequestHandler();
	LoginManager& getLoginManager();

private:
	LoginManager m_loginManager;
	IDatabase* m_database;
};

