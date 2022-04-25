#pragma once
#include "responses.h"

class JsonResponsePacketSerializer {
public:
	static std::string serializeResponse(ErrorResponse resp);
	static std::string serializeResponse(LoginResponse resp);
	static std::string serializeResponse(SignupResponse resp);
};