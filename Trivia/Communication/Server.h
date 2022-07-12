#pragma once
#include "../Communication/Communicator.h"
#include "../Databases/IDatabase.h"
#include "../Handlers/RequestHandlerFactory.h"

class Server
{
public:
	Server();
	void run();
	~Server();

private:
	Communicator m_communicator;
	IDatabase* m_database;
	RequestHandlerFactory m_handlerFactory;
};
