#pragma once
#include "IRequestHandler.h"
#include "msgCodes.h"

class LoginRequestHandler : public IRequestHandler {
public:
	//check if the message code is valid
	bool isRequestRelevant(RequestInfo req) override;
	RequestResult handleRequest(RequestInfo req) override;
};