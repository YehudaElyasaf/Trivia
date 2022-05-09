#include "RequestHandlerFactory.h"

RequestHandlerFactory::RequestHandlerFactory(IDatabase* database) : m_loginManager(database) {
    m_database = database;
}

LoginRequestHandler* RequestHandlerFactory::createLoginRequestHandler() {
    return new LoginRequestHandler(m_loginManager, *this);
}

MenuRequestHandler* RequestHandlerFactory::createMenuRequestHandler() {
    return new MenuRequestHandler();
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
