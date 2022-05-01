#include "RequestHandlerFactory.h"

LoginRequestHandler* RequestHandlerFactory::createLoginRequestHandler() {
    return new LoginRequestHandler();
}

LoginManager& RequestHandlerFactory::getLoginManager() {
    return m_loginManager;
}
