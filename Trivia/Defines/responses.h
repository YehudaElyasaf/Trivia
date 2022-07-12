#pragma once
#include <string>
#include <map>
#include "../Room/Room.h"

struct LoginResponse {
	unsigned int status;
};

struct SignupResponse {
	unsigned int status;
};

struct ErrorResponse {
	std::string message;
};

struct LogoutResponse {
	unsigned int status;
};

struct GetRoomsResponse {
	unsigned int status;
	std::vector<RoomData> rooms;
};

struct GetPlayersInRoomResponse {
	std::vector<std::string> players;
};

struct JoinRoomResponse {
	unsigned int status;
};

struct CreateRoomResponse {
	unsigned int status;
};

struct GetHighScoreResponse {
	unsigned int status;
	std::vector<std::string> statistics;
};

struct GetPersonalStatsResponse {
	unsigned int status;
	//a vector with the statistics of an user
	/*
	* indexes:
	* 1 - AverageAnswerTime
	* 2 - NumOfCorrectAnswers
	* 3 - NumOfTotalAnswers
	* 4 - NumOfPlayerGames
	*/

	std::vector<std::string> statistics;
};

struct CloseRoomResponse {
	unsigned int status;
};

struct StartGameResponse {
	unsigned int status;
};

struct GetRoomStateResponse {
	unsigned int status;
	bool hasGameBegun;
	std::vector<LoggedUser> players;
	unsigned int questionCount;
	unsigned int answerTimeout;
};

struct LeaveRoomResponse {
	unsigned int status;
};

struct LeaveGameResponse {
	unsigned int status;
};

struct GetQuestionResponse {
	unsigned int status;
	std::string question;
	std::vector<std::string> answers;
};

struct SubmitAnswerResponse {
	unsigned int status;
	std::string correctAnswer;
};

struct PlayerResult {
	//for some reason the linker asked me to add this c'tor
	PlayerResult(const std::string& username, const unsigned int correctAnswerCount, const unsigned int wrongAnswerCount, const int averageAnswerTime) {
		this->username = username;
		this->correctAnswerCount = correctAnswerCount;
		this->wrongAnswerCount = wrongAnswerCount;
		this->averageAnswerTime = averageAnswerTime;
	}

	std::string username;
	unsigned int correctAnswerCount;
	unsigned int wrongAnswerCount;
	int averageAnswerTime;
};

struct GetGameResultsResponse {
	unsigned int status;
	std::vector<PlayerResult> results;
};