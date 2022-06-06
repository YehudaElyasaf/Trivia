#pragma once
#include <ctime>
#include <string>

class IRequestHandler;

struct RequestInfo {
	int id;
	time_t receivalTime;
	std::string buffer;
};

struct RequestResult {
	std::string response;
	IRequestHandler* newHandler;
};


class IRequestHandler {
public:
	virtual ~IRequestHandler()=default;
	virtual bool isRequestRelevant(struct RequestInfo req)=0;
	virtual RequestResult handleRequest(struct RequestInfo req)=0;
	virtual std::string getUsername() const = 0;
};