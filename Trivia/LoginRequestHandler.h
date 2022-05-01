#pragma once
#include "IRequestHandler.h"
#include "msgCodes.h"

class LoginRequestHandler : public IRequestHandler {
public:
	//check if the message code is valid
	bool isRequestRelevant(RequestInfo req) override;
	RequestResult handleRequest(RequestInfo req) override;

private:
	LoginManager& m_loginManager;
	RequestHandlerFactory& m_handlerFactory;
	RequestResult login(RequestInfo req);
	RequestResult signup(RequestInfo req);
};