#pragma once
#include "Communicator.h"

class Server
{
public:
	void run();

private:
	Communicator _communicator;
};
