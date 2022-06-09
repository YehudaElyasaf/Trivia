#include "GameManager.h"

GameManager::GameManager(IDatabase* database) :
	m_database(database), m_nextId(0) {}

Game& GameManager::createGame(const Room& room)
{
	std::list<Question> questions = m_database->getQuestions(room.getRoomData().numOfQuestionsInGame);

	m_nextId++;
	Game game(questions, room.getAllUsers(), m_nextId);
	m_games[m_nextId] = game;

	return m_games[m_nextId];
}

bool GameManager::deleteGame(const unsigned int id)
{
	std::map<LoggedUser, GameData> players = m_games.at(id).getPlayers();
	for (auto it = players.begin(); it != players.end(); it++) {
		m_database->addToAnswerTime(it->first.m_username, it->second.totalAnswerTime);
		m_database->addToCorrectAnswers(it->first.m_username, it->second.correctAnswerCount);
		m_database->addToTotalAnswers(it->first.m_username, it->second.currentQuestionId);
		m_database->increaseTotalGames(it->first.m_username);
	}

	return m_games.erase(id) == KEY_FOUND_IN_MAP;
}
