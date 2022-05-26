#include "../Serializing/JsonResponsePacketSerializer.h"
#include "../Defines/msgCodes.h"

std::string JsonResponsePacketSerializer::bitwiseLen(const json& data) {
	std::string out;
	int dataLen = data.dump().length();
	unsigned char* len = (unsigned char*)&dataLen;

	for (int i = 0; i < sizeof(int); i++) {
		out += len[i];
	}
	return out;
}

std::string JsonResponsePacketSerializer::join(const std::vector<std::string>& list, const std::string& divider) {
	std::string out;
	if (list.size() == 0)
		//empty vector
		return "";

	out = list[0];
	for (int i = 1; i < list.size(); i++)
		out += divider + list[i];
	return out;
}

std::string JsonResponsePacketSerializer::serializeResponse(const ErrorResponse& resp) {
	std::string out = { (unsigned char)ERROR_CODE };
	json data{ {"message", resp.message} };

	out += bitwiseLen(data);
	out += data.dump();
	return out;
}

std::string JsonResponsePacketSerializer::serializeResponse(const LoginResponse& resp) {
	std::string out = { (unsigned char)LOGIN_CODE };
	json data{ {"status", resp.status} };

	out += bitwiseLen(data);
	out += data.dump();
	return out;
}

std::string JsonResponsePacketSerializer::serializeResponse(const SignupResponse& resp) {
	std::string out = { (unsigned char)SIGNUP_CODE };
	json data{ {"status", resp.status} };

	out += bitwiseLen(data);
	out += data.dump();
	return out;
}

std::string JsonResponsePacketSerializer::serializeResponse(const LogoutResponse& resp) {
	std::string out = { (unsigned char)LOGOUT_CODE };
	json data{ {"status", resp.status} };

	out += bitwiseLen(data);
	out += data.dump();
	return out;
}

std::string JsonResponsePacketSerializer::serializeResponse(const GetRoomsResponse& resp) {
	std::string out = { (unsigned char)GET_ROOMS_CODE };
	std::string rooms = "", ids = "";
	json data{ {"status", resp.status} };

	if (resp.rooms.size() > 0) {
		// cant use join method because it's not vector of strings
		rooms = resp.rooms[0].name;
		ids = std::to_string(resp.rooms[0].id);
		for (int i = 1; i < resp.rooms.size(); i++) {
			rooms += DIVIDER + resp.rooms[i].name;
			ids += DIVIDER + std::to_string(resp.rooms[i].id);
		}
	}
	data["Rooms"] = rooms;
	data["Ids"] = ids;

	out += bitwiseLen(data);
	out += data.dump();
	return out;
}

std::string JsonResponsePacketSerializer::serializeResponse(const GetPlayersInRoomResponse& resp) {
	std::string out = { (unsigned char)GET_PLAYERS_CODE };
	json data{ {"PlayersInRoom", join(resp.players)} };

	out += bitwiseLen(data);
	out += data.dump();
	return out;
}

std::string JsonResponsePacketSerializer::serializeResponse(const JoinRoomResponse& resp) {
	std::string out = { (unsigned char)JOIN_ROOM_CODE };
	json data{ {"status", resp.status} };

	out += bitwiseLen(data);
	out += data.dump();
	return out;
}

std::string JsonResponsePacketSerializer::serializeResponse(const CreateRoomResponse& resp) {
	std::string out = { (unsigned char)CREATE_ROOM_CODE };
	json data{ {"status", resp.status} };

	out += bitwiseLen(data);
	out += data.dump();
	return out;
}

std::string JsonResponsePacketSerializer::serializeResponse(const GetHighScoreResponse& resp) {
	std::string out = { (unsigned char)HIGH_SCORE_CODE };
	json data{ {"status", resp.status}, {"HighScores", join(resp.statistics)} };

	out += bitwiseLen(data);
	out += data.dump();
	return out;
}

std::string JsonResponsePacketSerializer::serializeResponse(const GetPersonalStatsResponse& resp) {
	std::string out = { (unsigned char)PERSONAL_STATS_CODE };
	json data{ {"status", resp.status}, {"UserStatistics", join(resp.statistics)} };

	out += bitwiseLen(data);
	out += data.dump();
	return out;
}
