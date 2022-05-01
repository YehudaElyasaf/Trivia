#pragma once
#include "Communicator.h"
#include "IDatabase.h"
#include "RequestHandlerFactory.h"

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
