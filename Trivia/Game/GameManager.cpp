#include "GameManager.h"

GameManager::GameManager(IDatabase* database) :
	m_database(database), m_nextId(0) {}

Game GameManager::createGame(const Room& room)
{
	std::list<Question> questions = m_database->getQuestions(room.getRoomData().numOfQuestionsInGame);

	m_nextId++;
	Game game(questions, room.getAllUsers(), m_nextId);
	m_games[m_nextId] = game;
}

bool GameManager::deleteGame(const unsigned int id)
{
	return m_games.erase(id) == KEY_FOUND_IN_MAP;
}
