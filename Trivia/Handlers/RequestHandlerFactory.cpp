#include "../Handlers/RequestHandlerFactory.h"

RequestHandlerFactory::RequestHandlerFactory(IDatabase* database) :
    m_database(database), m_loginManager(database), m_statisticsManager(database), m_communicator(nullptr) {}

LoginRequestHandler* RequestHandlerFactory::createLoginRequestHandler() {
    return new LoginRequestHandler(m_loginManager, *this);
}

MenuRequestHandler* RequestHandlerFactory::createMenuRequestHandler(std::string& username) {
    return new MenuRequestHandler(username, m_roomManager, m_statisticsManager);
}

LoginManager& RequestHandlerFactory::getLoginManager() {
    return m_loginManager;
}

StatisticsManager& RequestHandlerFactory::getStatisticsManager() {
    return m_statisticsManager;
}

RoomManager& RequestHandlerFactory::getRoomManager() {
    return m_roomManager;
}

void RequestHandlerFactory::setCommunicator(Communicator* communicator) {
    m_communicator = communicator;
}

Communicator* RequestHandlerFactory::getCommunicator() {
    return m_communicator;
}
