#include "GameManager.h"

GameManager::GameManager(const IDatabase* database) :
	m_database(database) {}

Game GameManager::createGame(const Room& room)
{
	std::vector<Question> questions = m_database->getQuestions(room.getRoomData().numOfQuestionsInGame);

	Game game(questions, room.getAllUsers());
	m_games.push_back(game);
}
