#pragma once
#include"../Login/LoggedUser.h"
#include"../Game/Question.h"
#include<vector>
#include<map>
#include<string>
#include<list>

#define KEY_FOUND_IN_MAP 1

struct GameData {
	unsigned int currentQuestionId;
	unsigned int correctAnswerCount;
	unsigned int wrongAnswerCount;
	unsigned int averageAnswerTime;
	unsigned int totalAnswerTime;
};

class Game {
private:
	std::vector<Question> m_questions;
	std::map<LoggedUser, GameData> m_players;
	unsigned int m_id;

public:
	Game(const std::list<Question>& questions, const std::vector<LoggedUser>& users, const unsigned int id);
	Question getQuestionForUser(const LoggedUser& user) const;
	void submitAnswer(const LoggedUser& user, const std::string& answer);
	bool removePlayer(const LoggedUser& user);
	int getId() const;
	std::map<LoggedUser, GameData> getPlayers() const;
};