#pragma once
#include "responses.h"
#include "json.h"

using json = nlohmann::json;

class JsonResponsePacketSerializer {
public:
	static std::string serializeResponse(const ErrorResponse& resp);
	static std::string serializeResponse(const LoginResponse& resp);
	static std::string serializeResponse(const SignupResponse& resp);

private:
	static std::string bitwiseLen(const json& data);
};