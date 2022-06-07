#pragma once
#include"../Login/LoggedUser.h"
#include"../Game/Question.h"
#include<vector>
#include<map>
#include<string>
#include<list>

struct GameData {
	unsigned int currentQuestion;
	unsigned int correctAnswerCount;
	unsigned int wrongAnswerCount;
	unsigned int totalAnswerTime;
};

class Game {
private:
	std::vector<Question> m_questions;
	std::map<LoggedUser, GameData> m_players;

public:
	Game(const std::list<Question>& questions, const std::vector<LoggedUser>& users);
	Question getQuestionForUser(const LoggedUser& user);
	void submitAnswer(const LoggedUser& user, const std::string& answer);
	void removePlayer(const LoggedUser& user);
};