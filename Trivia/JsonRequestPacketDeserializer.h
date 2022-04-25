#pragma once
#include "requests.h"

class JsonRequestPacketDeserializer {
public:
	static LoginRequest deserializeLoginRequest(std::string buffer);
	static SignupRequest deserializeSignupRequest(std::string buffer);
};