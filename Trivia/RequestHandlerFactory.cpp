#include "RequestHandlerFactory.h"

RequestHandlerFactory::RequestHandlerFactory(IDatabase* database) { 
    m_database = database;
    m_loginManager = LoginManager(database);
}

LoginRequestHandler* RequestHandlerFactory::createLoginRequestHandler() {
    return new LoginRequestHandler(m_loginManager, *this);
}

LoginManager& RequestHandlerFactory::getLoginManager() {
    return m_loginManager;
}
