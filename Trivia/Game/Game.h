#pragma once
#include"../Login/LoggedUser.h"
#include"../Game/Question.h"
#include<vector>
#include<map>
#include<string>
#include<list>
#include<chrono>

#define KEY_FOUND_IN_MAP 1
#define NO_AVERAGE_ANSWER_TIME -1

struct GameData {
	int currentQuestionId;
	unsigned int correctAnswerCount;
	unsigned int wrongAnswerCount;
	int totalAnswerTime;
	int averageAnswerTime;
	std::chrono::steady_clock::time_point questionBeginningTime;
};

class Game {
public:
	Game();
	Game(const std::list<Question>& questions, const std::vector<LoggedUser>& users, const unsigned int id, const unsigned int maxQuestionTime);
	Question getQuestionForUser(const LoggedUser& user) const;
	void submitAnswer(const LoggedUser& user, const std::string& answer);
	bool removePlayer(const LoggedUser& user);
	int getId() const;
	std::map<LoggedUser, GameData> getPlayers() const;
	bool isGameFinished() const;

private:
	std::vector<Question> m_questions;
	std::map<LoggedUser, GameData> m_players;
	unsigned int m_id;
	unsigned int m_maxQuestionTime;
};