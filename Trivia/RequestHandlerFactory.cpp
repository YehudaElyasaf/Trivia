#include "RequestHandlerFactory.h"

RequestHandlerFactory::RequestHandlerFactory(IDatabase* database) : m_loginManager(database) {
    m_database = database;
}

LoginRequestHandler* RequestHandlerFactory::createLoginRequestHandler() {
    return new LoginRequestHandler(m_loginManager, *this);
}

LoginManager& RequestHandlerFactory::getLoginManager() {
    return m_loginManager;
}
