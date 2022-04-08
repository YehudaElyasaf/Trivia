#pragma once
#include <WinSock2.h>
#include <Windows.h>
#include <map>
#include "IRequestHandler.h"

#define PORT 424242

class Communicator
{
public:
	Communicator();

	void startHandleRequests();

	// added to stop all of the threads
	void stop();

private:
	SOCKET _serverSocket;
	std::map<SOCKET, IRequestHandler*> _clients;
	// added to stop all of the threads
	bool _running;

	void bindAndListen();
	void handleNewClient(SOCKET sock);
};

