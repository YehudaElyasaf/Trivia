#pragma once
#include "requests.h"
#include "msgCodes.h"
#include "json.h"

using json = nlohmann::json;

class JsonRequestPacketDeserializer {
public:
	static LoginRequest deserializeLoginRequest(const std::string& buffer);
	static SignupRequest deserializeSignupRequest(const std::string& buffer);
};