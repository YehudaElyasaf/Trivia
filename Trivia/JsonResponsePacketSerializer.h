#pragma once
#include "responses.h"
#include "json.h"

using json = nlohmann::json;

class JsonResponsePacketSerializer {
public:
	static std::string serializeResponse(ErrorResponse resp);
	static std::string serializeResponse(LoginResponse resp);
	static std::string serializeResponse(SignupResponse resp);

private:
	static std::string bitwiseLen(json data);
};