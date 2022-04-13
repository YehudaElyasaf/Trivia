#pragma once
#include "Communicator.h"

class Server
{
public:
	void run();
	~Server();

private:
	Communicator _communicator;
};
