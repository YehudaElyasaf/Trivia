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
std::string JsonResponsePacketSerializer::join(const std::vector<LoggedUser>& list, const std::string& divider) {
	std::vector<std::string> stringList;
	for (LoggedUser loggedUser : list)
		stringList.push_back(loggedUser.m_username);

	return join(stringList, divider);
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

std::string JsonResponsePacketSerializer::serializeResponse(const CloseRoomResponse& resp)
{
	std::string out = { (unsigned char)CLOSE_ROOM_CODE };
	json data{ {"status", resp.status} };

	out += bitwiseLen(data);
	out += data.dump();
	return out;
}

std::string JsonResponsePacketSerializer::serializeResponse(const StartGameResponse& resp)
{
	std::string out = { (unsigned char)START_GAME_CODE };
	json data{ {"status", resp.status} };

	out += bitwiseLen(data);
	out += data.dump();
	return out;
}

std::string JsonResponsePacketSerializer::serializeResponse(const GetRoomStateResponse& resp) {
	std::string out = { (unsigned char)GET_ROOM_STATE_CODE };
	json data{ {"status", resp.status}, {"HasGameBegun", resp.hasGameBegun}, {"Players", join(resp.players)}, {"QuestionCount", resp.questionCount}, {"AnswerTimeout",resp.answerTimeout} };

	out += bitwiseLen(data);
	out += data.dump();
	return out;
}

std::string JsonResponsePacketSerializer::serializeResponse(const LeaveRoomResponse& resp) {
	std::string out = { (unsigned char)LEAVE_ROOM_CODE };
	json data{ {"status", resp.status} };

	out += bitwiseLen(data);
	out += data.dump();
	return out;
}

std::string JsonResponsePacketSerializer::serializeResponse(const LeaveGameResponse& resp) {
	std::string out = { (unsigned char)LEAVE_GAME_CODE };
	json data{ {"status", resp.status} };

	out += bitwiseLen(data);
	out += data.dump();
	return out;
}

std::string JsonResponsePacketSerializer::serializeResponse(const GetGameResultsResponse& resp) {
	std::string out = { (unsigned char)GET_RESULTS_CODE };
	json data{ {"status", resp.status}, {"Results", serializeResults(resp.results)}};

	out += bitwiseLen(data);
	out += data.dump();
	return out;
}

std::string JsonResponsePacketSerializer::serializeResponse(const GetQuestionResponse& resp) {
	std::string out = { (unsigned char)GET_QUESTION_RESP_CODE };

	json data{ {"status", resp.status}, {"Question", resp.question}, {"Ans1", resp.answers.at(0)}, {"Ans1", resp.answers.at(0)}, {"Ans2", resp.answers.at(1)}, {"Ans3", resp.answers.at(2)}, {"Ans4", resp.answers.at(3)}};

	out += bitwiseLen(data);
	out += data.dump();
	return out;
}

std::string JsonResponsePacketSerializer::serializeResponse(const SubmitAnswerResponse& resp) {
	std::string out = { (unsigned char)SUBMIT_ANS_CODE };
	json data{ {"status", resp.status}, {"CorrectAns", resp.correctAnswer} };

	out += bitwiseLen(data);
	out += data.dump();
	return out;
}

std::vector<std::map<std::string, std::string>> JsonResponsePacketSerializer::serializeResults(std::vector<PlayerResult> results) {
	std::vector<std::map<std::string, std::string>> out;
	std::map<std::string, std::string> tmp;
	
	for (PlayerResult res : results) {
		tmp = std::map<std::string, std::string>();
		tmp["Username"] = res.username;
		tmp["AverageAnswerTime"] = res.averageAnswerTime;
		tmp["CorrectAnswerCount"] = res.correctAnswerCount;
		tmp["WrongAnswerCount"] = res.wrongAnswerCount;

		out.push_back(tmp);
	}

	return out;
}