#pragma once
#include "../Defines/msgCodes.h"
#include "../Handlers/IRequestHandler.h"
#include "../Handlers/RequestHandlerFactory.h"
#include "../Login/LoginManager.h"

class RequestHandlerFactory;

class LoginRequestHandler : public IRequestHandler {
public:
	LoginRequestHandler(LoginManager& manager, RequestHandlerFactory& factory);
	//check if the message code is valid
	bool isRequestRelevant(RequestInfo req) override;
	RequestResult handleRequest(RequestInfo req) override;
	std::string getUsername() const { throw std::exception("Action not supported, no user logged in\n"); }

private:
	LoginManager& m_loginManager;
	RequestHandlerFactory& m_handlerFactory;
	RequestResult login(RequestInfo req);
	RequestResult signup(RequestInfo req);
};