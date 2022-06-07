#pragma once
#include"../Login/LoggedUser.h"
#include"../Game/Question.h"
#include<vector>
#include<map>
#include<string>

struct GamaData {
	Question currentQuestion;
	unsigned int correctAnswerCount;
	unsigned int wrongAnswerCount;
	unsigned int averageAnswerTime;
};

class Game {
private:
	std::vector<Question> m_questions;
	std::map<LoggedUser, GamaData> m_players;

public:
	Game(const std::map<LoggedUser, GamaData>& players);
	Question getQuestionForUser(const LoggedUser& user);
	void submitAnswer(const LoggedUser& user, const std::string& answer);
	void removePlayer(const LoggedUser& user);
};