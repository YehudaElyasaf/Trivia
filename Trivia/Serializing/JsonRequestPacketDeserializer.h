#pragma once
#include "../Defines/requests.h"
#include "../Defines/msgCodes.h"
#include "../lib/json.h"

using json = nlohmann::json;

class JsonRequestPacketDeserializer {
public:
	static LoginRequest deserializeLoginRequest(const std::string& buffer);
	static SignupRequest deserializeSignupRequest(const std::string& buffer);
	static GetPlayersInRoomRequest deserializeGetPlayersInRoomRequest(const std::string& buffer);
	static JoinRoomRequest deserializeJoinRoomRequest(const std::string& buffer);
	static CreateRoomRequest deserializeCreateRoomRequest(const std::string& buffer);
	static SubmitAnswerRequest deserializeSubmitAnswerRequest(const std::string& buffer);
};