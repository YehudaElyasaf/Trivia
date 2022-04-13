#pragma once
#include "WSAInitializer.h"
#include <map>
#include "IRequestHandler.h"

#define PORT 4242

class Communicator
{
public:
	Communicator();

	void startHandleRequests();

	// added to stop all of the threads
	void stop();

private:
	WSAInitializer _initServer;
	SOCKET _serverSocket;
	std::map<SOCKET, IRequestHandler*> _clients;
	// added to stop all of the threads
	bool _running;

	void bindAndListen();
	void handleNewClient(SOCKET sock);
};

