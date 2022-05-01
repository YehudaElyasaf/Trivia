#pragma once
#include "WSAInitializer.h"
#include <map>
#include "IRequestHandler.h"

#define SERVER_PORT 4242

class Communicator {
public:
	Communicator(RequestHandlerFactory& factory);
	void startHandleRequests();

	// added to stop all of the threads
	void stop();

private:
	WSAInitializer m_initServer;
	SOCKET m_serverSocket;
	std::map<SOCKET, IRequestHandler*> m_clients;
	RequestHandlerFactory& m_handlerFactory;

	// added to stop all of the threads
	bool m_running;

	void bindAndListen();
	void handleNewClient(SOCKET sock);
};

