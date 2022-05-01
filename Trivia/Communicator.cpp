#include "Communicator.h"
#include "LoginRequestHandler.h"
#include <thread>
#include <iostream>
#include "Helper.h"
#include "LoginRequestHandler.h"
#include "JsonResponsePacketSerializer.h"
#include "JsonRequestPacketDeserializer.h"

#define HELLO_MSG "Hello"
#define EXIT_MSG  "Exit"
#define MESSAGE_CODE_LENGTH 1

Communicator::Communicator() : _running(true), _initServer() {
	try {
		_serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

		if (_serverSocket == INVALID_SOCKET)
			throw std::exception(__FUNCTION__ " - socket");
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << "\n Error Code: " << WSAGetLastError() << std::endl;
	}
};

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

		sockAddrIn.sin_port = htons(SERVER_PORT); // port that server will listen for
		sockAddrIn.sin_family = AF_INET;   // must be AF_INET
		sockAddrIn.sin_addr.s_addr = INADDR_ANY;    // when there are few ip's for the machine. We will use always "INADDR_ANY"

		// Connects between the socket and the configuration (port and etc..)
		if (bind(_serverSocket, (struct sockaddr*)&sockAddrIn, sizeof(sockAddrIn)) == SOCKET_ERROR)
			throw std::exception(__FUNCTION__ " - bind");

		// Start listening for incoming requests of clients
		if (listen(_serverSocket, SOMAXCONN) == SOCKET_ERROR)
			throw std::exception(__FUNCTION__ " - listen");
		std::cout << "Listening on port " << SERVER_PORT << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << "\nError Code: " << WSAGetLastError() << std::endl;
	}
	
	while (_running) {
		try {
			SOCKET clientSocket = accept(_serverSocket, NULL, NULL);
			if (clientSocket == INVALID_SOCKET)
				throw std::exception(__FUNCTION__ " - invalid socket");

			std::cout << "Client accepted. Server and client can speak" << std::endl;
			// the function that handle the conversation with the client
			std::thread(&Communicator::handleNewClient, this, clientSocket).detach();
			_clients.emplace(clientSocket, new LoginRequestHandler);
		}
		catch (const std::exception& e) {
			std::cerr << e.what() << std::endl;
			std::cerr << "Error Code: " << WSAGetLastError() << std::endl;
		}
	}
}

void Communicator::handleNewClient(SOCKET sock) {
	std::string lastMsg;
	Helper::sendData(sock, HELLO_MSG);
	try {
		while (_running && lastMsg != EXIT_MSG) {
			// get first 5 bytes of the message
			lastMsg = Helper::getStringPartFromSocket(sock, MESSAGE_CODE_LENGTH);
			int dataLen = Helper::getDataLengthFromSockect(sock);
			lastMsg += Helper::getStringPartFromSocket(sock, dataLen);

			// check it request relevant and serialize and send a response based on the request type
			LoginRequestHandler log;
			RequestInfo req = { 0, time(0), lastMsg };
			std::string responseBytes;
			if (log.isRequestRelevant(req)) {
				if (lastMsg[0] == LOGIN_CODE) {
					LoginResponse resp = { 1 };
					responseBytes = JsonResponsePacketSerializer::serializeResponse(resp);
				}
				else {
					SignupResponse resp = { 1 };
					responseBytes = JsonResponsePacketSerializer::serializeResponse(resp);
				}
			}
			else {
				ErrorResponse resp = { "Err" };
				responseBytes = JsonResponsePacketSerializer::serializeResponse(resp);
			}

			Helper::sendData(sock, responseBytes);
		}
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	closesocket(sock);
}
