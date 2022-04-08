#include "Server.h"
#include <string>
#include <iostream>

int main() {
	Server s;
	s.run();
}

void Server::run() {
	_communicator.startHandleRequests();

	std::string cmd;
	while (cmd != "EXIT") {
		std::cin >> cmd;
	}
}

Server::~Server() {
	_communicator.stop();
}