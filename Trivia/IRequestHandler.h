#pragma once
#include <ctime>
#include <string>

struct RequestInfo {
	int id;
	time_t receivalTime;
	std::string buffer;
};

struct RequestResult {
	std::string result;
	IRequestHandler* newHandler;
};

class IRequestHandler {
public:
	virtual bool isRequestRelevant(RequestInfo req)=0;
	virtual RequestResult handleRequest(RequestInfo req)=0;
};