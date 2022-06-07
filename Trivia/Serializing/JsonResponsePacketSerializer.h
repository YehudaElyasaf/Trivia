#pragma once
#include "../Defines/responses.h"
#include "../lib/json.h"

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
	static std::string serializeResponse(const CloseRoomResponse& resp);
	static std::string serializeResponse(const StartGameResponse& resp);
	static std::string serializeResponse(const GetRoomStateResponse& resp);
	static std::string serializeResponse(const LeaveRoomResponse& resp);
	static std::string serializeResponse(const LeaveGameResponse& resp);
	static std::string serializeResponse(const GetGameResultsResponse& resp);
	static std::string serializeResponse(const GetQuestionResponse& resp);
	static std::string serializeResponse(const SubmitAnswerResponse& resp);


	// get the length (in bytes) of a json's string
	static std::string bitwiseLen(const json& data);
	static std::string join(const std::vector<std::string>& list, const std::string& divider = DIVIDER);
	static std::string join(const std::vector<LoggedUser>& list, const std::string& divider = DIVIDER);
	static std::vector<std::map<std::string, std::string>> serializeResults(std::vector<PlayerResult> results);
};