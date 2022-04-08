#pragma once
#include <WinSock2.h>
#include <Windows.h>
#include <map>
#include "IRequestHandler.h"

class Communicator
{
public:
	void startHandleRequests();

private:
	SOCKET _serverSocket;
	std::map<SOCKET, IRequestHandler*> _clients;

	void bindAndListen();
	void handleNewClient(SOCKET sock);
};

