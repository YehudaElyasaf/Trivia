#pragma once
#include "responses.h"
#include "json.h"

#define DIVIDER ","

using json = nlohmann::json;

class JsonResponsePacketSerializer {
public:
	static std::string serializeResponse(const ErrorResponse& resp);
	static std::string serializeResponse(const LoginResponse& resp);
	static std::string serializeResponse(const SignupResponse& resp);
	static std::string serializeResponse(const LogoutResponse& resp);
	static std::string serializeResponse(const GetRoomsResponse& resp);
	static std::string serializeResponse(const GetPlayersInRoomResponse& resp);
	static std::string serializeResponse(const JoinRoomResponse& resp);
	static std::string serializeResponse(const CreateRoomResponse& resp);
	static std::string serializeResponse(const GetHighScoreResponse& resp);
	static std::string serializeResponse(const GetPersonalStatsResponse& resp);


	// get the length (in bytes) of a json's string
	static std::string bitwiseLen(const json& data);
	static std::string join(const std::vector<std::string>& list, const std::string& divider=DIVIDER);
};