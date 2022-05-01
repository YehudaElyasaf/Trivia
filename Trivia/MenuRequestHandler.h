#pragma once
#include "IRequestHandler.h"

class MenuRequestHandler : public IRequestHandler {
public:
	bool isRequestRelevant(struct RequestInfo req) override;
	RequestResult handleRequest(struct RequestInfo req) override;
};