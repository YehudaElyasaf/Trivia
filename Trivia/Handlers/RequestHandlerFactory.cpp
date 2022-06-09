#include "../Handlers/RequestHandlerFactory.h"

RequestHandlerFactory::RequestHandlerFactory(IDatabase* database) :
    m_database(database), m_loginManager(database), m_statisticsManager(database), m_communicator(nullptr), m_gameManager(database) {}

LoginRequestHandler* RequestHandlerFactory::createLoginRequestHandler() {
    return new LoginRequestHandler(m_loginManager, *this);
}

MenuRequestHandler* RequestHandlerFactory::createMenuRequestHandler(const std::string& username) {
    return new MenuRequestHandler(username, m_roomManager, m_statisticsManager, *this);
}

RoomAdminRequestHandler* RequestHandlerFactory::createRoomAdminRequestHandler(const std::string& username, const unsigned int roomId) {
    return new RoomAdminRequestHandler(roomId, {username}, m_roomManager, m_gameManager, *this);
}

RoomMemberRequestHandler* RequestHandlerFactory::createRoomMemberRequestHandler(const std::string& username, const unsigned int roomId) {
    return new RoomMemberRequestHandler(roomId, {username}, m_roomManager, *this);
}

GameRequestHandler* RequestHandlerFactory::createGameRequestHandler(const std::string& username, const unsigned int roomId, Game& game) {
    return new GameRequestHandler(roomId, {username}, m_roomManager, *this, game);
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
