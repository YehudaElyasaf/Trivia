#include "../Communication/Server.h"
#include "../Databases/SQLiteDatabase.h"
#include <string>
#include <iostream>

int main() {
	Server s;
	s.run();
}

Server::Server() :
	m_database(new SQLiteDatabase()), m_handlerFactory(m_database), m_communicator(m_handlerFactory) {
	m_handlerFactory.setCommunicator(&m_communicator);
}

void Server::run() {
	m_communicator.startHandleRequests();

	std::string cmd;
	while (cmd != "EXIT") {
		std::cin >> cmd;
	}
}

Server::~Server() {
	m_communicator.stop();
	delete m_database;
}