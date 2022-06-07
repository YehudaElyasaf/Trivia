#include"Game.h"

Game::Game(const std::vector<Question>& questions, const std::vector<LoggedUser>& users) :
	m_questions(questions)
{
	for (LoggedUser user : users)
		m_players[user] = { 0,0,0,0 };
}