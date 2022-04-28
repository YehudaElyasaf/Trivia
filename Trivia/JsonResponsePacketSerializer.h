#pragma once
#include "responses.h"
#include "json.h"

using json = nlohmann::json;

class JsonResponsePacketSerializer {
public:
	static std::string serializeResponse(const ErrorResponse& resp);
	static std::string serializeResponse(const LoginResponse& resp);
	static std::string serializeResponse(const SignupResponse& resp);

	// get the length (in bytes) of a json's string
	static std::string bitwiseLen(const json& data);
};