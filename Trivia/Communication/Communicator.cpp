#include "../Communication/Communicator.h"
#include "../Handlers/LoginRequestHandler.h"
#include <thread>
#include <iostream>
#include "../Communication/Helper.h"
#include "../Handlers/LoginRequestHandler.h"
#include "../Serializing/JsonResponsePacketSerializer.h"
#include "../Serializing/JsonRequestPacketDeserializer.h"

#define HELLO_MSG "Hello"
#define EXIT_MSG  "Exit"
#define MESSAGE_CODE_LENGTH 1

Communicator::Communicator(RequestHandlerFactory& factory) : m_running(true), m_initServer(), m_handlerFactory(factory) {
	try {
		m_serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

		if (m_serverSocket == INVALID_SOCKET)
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
	m_running = false;
}

void Communicator::bindAndListen() {
	if (!m_running)
		return;

	try {
		struct sockaddr_in sockAddrIn = { 0 };

		sockAddrIn.sin_port = htons(SERVER_PORT); // port that server will listen for
		sockAddrIn.sin_family = AF_INET;   // must be AF_INET
		sockAddrIn.sin_addr.s_addr = INADDR_ANY;    // when there are few ip's for the machine. We will use always "INADDR_ANY"

		// Connects between the socket and the configuration (port and etc..)
		if (bind(m_serverSocket, (struct sockaddr*)&sockAddrIn, sizeof(sockAddrIn)) == SOCKET_ERROR)
			throw std::exception(__FUNCTION__ " - bind");

		// Start listening for incoming requests of clients
		if (listen(m_serverSocket, SOMAXCONN) == SOCKET_ERROR)
			throw std::exception(__FUNCTION__ " - listen");
		std::cout << "Listening on port " << SERVER_PORT << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << "\nError Code: " << WSAGetLastError() << std::endl;
	}

	while (m_running) {
		try {
			SOCKET clientSocket = accept(m_serverSocket, NULL, NULL);
			if (clientSocket == INVALID_SOCKET)
				throw std::exception(__FUNCTION__ " - invalid socket");

			std::cout << "Client accepted. Server and client can speak" << std::endl;
			// the function that handle the conversation with the client
			std::thread(&Communicator::handleNewClient, this, clientSocket).detach();
			m_clients.emplace(clientSocket, nullptr); // !!!replace later!!!
		}
		catch (const std::exception& e) {
			std::cerr << e.what() << std::endl;
			std::cerr << "Error Code: " << WSAGetLastError() << std::endl;
		}
	}
}

void Communicator::handleNewClient(SOCKET sock) {
	std::string lastMsg, username;
	LoginRequestHandler* loginHandler = m_handlerFactory.createLoginRequestHandler();
	Helper::sendData(sock, HELLO_MSG);

	try {
		while (m_running && lastMsg != EXIT_MSG) {
			// get first 5 bytes of the message
			lastMsg = Helper::getStringPartFromSocket(sock, MESSAGE_CODE_LENGTH);
			int dataLen = Helper::getDataLengthFromSockect(sock);
			lastMsg += Helper::getStringPartFromSocket(sock, dataLen);

			// check it request relevant and serialize and send a response based on the request type
			RequestInfo req = { 0, time(0), lastMsg };
			std::string responseBytes;
			RequestResult res;

			if (loginHandler->isRequestRelevant(req)) {
				res = loginHandler->handleRequest(req);
				json responseJson = json::parse(res.response.substr(MESSAGE_CODE_LENGTH + MESSAGE_LENGTH_FIELD_LENGTH));
				if (responseJson["status"] == 1) {
					username = json::parse(req.buffer.substr(MESSAGE_CODE_LENGTH))["username"];
				}
			}
			else {
				res = RequestResult{ JsonResponsePacketSerializer::serializeResponse(ErrorResponse{ "Invalid code" }), nullptr };
			}

			Helper::sendData(sock, res.response);
		}
	}
	catch (const std::exception& e) {
		std::cout << e.what() << ". socket " << sock << " disconnected\n";
		closesocket(sock);
		delete m_clients[sock];
		m_handlerFactory.getLoginManager().logout(username);
		delete loginHandler;
	}
}
