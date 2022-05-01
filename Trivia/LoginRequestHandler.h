#pragma once
#include "msgCodes.h"
#include "IRequestHandler.h"
#include "RequestHandlerFactory.h"

class LoginRequestHandler : public IRequestHandler {
public:
	LoginRequestHandler(LoginManager& manager, RequestHandlerFactory& factory);
	//check if the message code is valid
	bool isRequestRelevant(RequestInfo req) override;
	RequestResult handleRequest(RequestInfo req) override;

private:
	LoginManager& m_loginManager;
	RequestHandlerFactory& m_handlerFactory;
	RequestResult login(RequestInfo req);
	RequestResult signup(RequestInfo req);
};