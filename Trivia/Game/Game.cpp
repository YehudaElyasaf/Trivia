#include "Game.h"
#include"Game.h"

Game::Game(const std::list<Question>& questions, const std::vector<LoggedUser>& users)
{
	//beima shell Magshimimm hem lo yachloo la'asot meha'athala sheashe'elot yahzero bevector?
	for (Question question : questions)
		m_questions.push_back(question);

	for (LoggedUser user : users)
		m_players[user] = { 0,0,0,0 };
}

bool Game::removePlayer(const LoggedUser& user)
{
	m_players.erase(user);
}
