#include "GameManager.h"

GameManager::GameManager(IDatabase* database) :
	m_database(database) {}

Game GameManager::createGame(const Room& room)
{
	std::list<Question> questions = m_database->getQuestions(room.getRoomData().numOfQuestionsInGame);

	Game game(questions, room.getAllUsers());
	m_games.push_back(game);
}
