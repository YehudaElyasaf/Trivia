#include "Game.h"

Game::Game(const std::list<Question>& questions, const std::vector<LoggedUser>& users, const unsigned int id) :
	m_id(id)
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
	return m_questions.at(currentQuestionId);

}

void Game::submitAnswer(const LoggedUser& user, const std::string& answer) {
	GameData& gameData = m_players.at(user);
	if (answer == m_questions.at(gameData.currentQuestionId).getCorrectAnswer())
		//correct answer
		gameData.correctAnswerCount++;
	else
		//wrong answer
		gameData.wrongAnswerCount++;

	gameData.currentQuestionId++;

	std::chrono::steady_clock::time_point now = std::chrono::steady_clock::now();
	gameData.totalAnswerTime = std::chrono::duration_cast<std::chrono::milliseconds>(now - gameData.beginningTime).count();
	gameData.averageAnswerTime = gameData.totalAnswerTime / gameData.currentQuestionId;
}

bool Game::removePlayer(const LoggedUser& user)
{
	return m_players.erase(user) == KEY_FOUND_IN_MAP;
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
