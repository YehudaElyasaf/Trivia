#pragma once
#include "IRequestHandler.h"
#include "msgCodes.h"

class LoginRequestHandler : public IRequestHandler {
public:
	bool isRequestRelevant(RequestInfo req) override;
	RequestResult handleRequest(RequestInfo req) override;
};