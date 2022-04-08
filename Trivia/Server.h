#pragma once
#include "Communicator.h"
#include "WSAInitializer.h"

class Server
{
public:
	void run();

private:
	Communicator _communicator;
	WSAInitializer init_server;
};
