#include "Communicator.h"
#include "LoginRequestHandler.h"
#include <thread>
#include <iostream>

Communicator::Communicator() : _running(true) {};

void Communicator::startHandleRequests() {
	std::thread t(&Communicator::bindAndListen, this);
	t.detach();
}

void Communicator::stop() {
	_running = false;
}

void Communicator::bindAndListen() {
	if (!_running)
		return;

	try {
		struct sockaddr_in sockAddrIn = { 0 };

		sockAddrIn.sin_port = htons(PORT); // port that server will listen for
		sockAddrIn.sin_family = AF_INET;   // must be AF_INET
		sockAddrIn.sin_addr.s_addr = INADDR_ANY;    // when there are few ip's for the machine. We will use always "INADDR_ANY"

		// Connects between the socket and the configuration (port and etc..)
		if (bind(_serverSocket, (struct sockaddr*)&sockAddrIn, sizeof(sockAddrIn)) == SOCKET_ERROR)
			throw std::exception(__FUNCTION__ " - bind");

		// Start listening for incoming requests of clients
		if (listen(_serverSocket, SOMAXCONN) == SOCKET_ERROR)
			throw std::exception(__FUNCTION__ " - listen");
		std::cout << "Listening on port " << PORT << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	while (_running) {
		try {
			SOCKET clientSocket = accept(_serverSocket, NULL, NULL);
			if (clientSocket == INVALID_SOCKET)
				throw std::exception(__FUNCTION__);

			std::cout << "Client accepted. Server and client can speak" << std::endl;
			// the function that handle the conversation with the client
			std::thread(&Communicator::handleNewClient, this, clientSocket).detach();
			_clients.emplace(clientSocket, new LoginRequestHandler());
		}
		catch (const std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
}

void Communicator::handleNewClient(SOCKET sock) {
	while (_running) {

	}
}
