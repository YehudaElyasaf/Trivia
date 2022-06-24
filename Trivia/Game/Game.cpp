#include "Game.h"
#include"../Defines/Exceptions.h"

Game::Game() :
	m_id(0)
{}

Game::Game(const std::list<Question>& questions, const std::vector<LoggedUser>& users, const unsigned int id, const unsigned int maxQuestionTime) :
	m_id(id), m_maxQuestionTime(maxQuestionTime)
{
	//beima shell Magshimimm hem lo yachloo la'asot meha'athala sheashe'elot yahzero bevector?
	for (Question question : questions)
		m_questions.push_back(question);

	for (LoggedUser user : users)
		m_players[user] = { 0, 0, 0, 0, NO_AVERAGE_ANSWER_TIME, std::chrono::steady_clock::now() };
}

Question Game::getQuestionForUser(const LoggedUser& user) const
{
	unsigned int currentQuestionId = m_players.at(user).currentQuestionId;
	if (currentQuestionId < m_questions.size())
		return m_questions.at(currentQuestionId);
	else
		throw std::exception("Question is out of range!");
}

std::string Game::submitAnswer(const LoggedUser& user, const std::string& answer) {
	GameData& gameData = m_players.at(user);

	//calculate gameData statistics
	std::chrono::steady_clock::time_point now = std::chrono::steady_clock::now();
	int currentQuestionAnswerTime = std::chrono::duration_cast<std::chrono::seconds>(now - gameData.questionBeginningTime).count();
	gameData.totalAnswerTime += currentQuestionAnswerTime;
	gameData.averageAnswerTime = gameData.totalAnswerTime / (gameData.currentQuestionId + 1); //+1 because index starts from 0

	//set the new question's new beginning time
	gameData.questionBeginningTime = now;

	//check if question time passed
	if (currentQuestionAnswerTime > m_maxQuestionTime) {
		gameData.wrongAnswerCount++;
		throw QuestionTimeOutException();
	}

		//check answer
		if (answer == m_questions.at(gameData.currentQuestionId).getCorrectAnswer())
			//correct answer
			gameData.correctAnswerCount++;
		else
			//wrong answer
			gameData.wrongAnswerCount++;

	return m_questions.at(gameData.currentQuestionId++).getCorrectAnswer();
}

bool Game::removePlayer(const LoggedUser& user)
{
	try {
		//set question id to one after the last id
		m_players.at(user).currentQuestionId = m_questions.size();
		return true;
	}
	catch (...) {
		//failed to remove
		return false;
	}
}

int Game::getId() const
{
	return m_id;
}

std::map<LoggedUser, GameData> Game::getPlayers() const
{
	return m_players;
}

bool Game::isGameFinished() const
{
	for (auto it = m_players.begin(); it != m_players.end(); it++)
		if (it->second.currentQuestionId < m_questions.size())
			//the player didn't answer all questions
			return false;

	return true;
}
