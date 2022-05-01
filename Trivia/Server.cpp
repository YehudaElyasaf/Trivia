#include "Server.h"
#include "SQLiteDatabase.h"
#include <string>
#include <iostream>

int main() {
	Server s;
	s.run();
}

Server::Server() {
	m_database = new SQLiteDatabase();
	m_handlerFactory = RequestHandlerFactory(m_database);
}

void Server::run() {
	m_communicator.startHandleRequests();
}

Server::~Server() {
	m_communicator.stop();
	delete m_database;
}