#include "../Game/Game.h"

#define KEY_FOUND_IN_MAP 1

Game::Game(const std::list<Question>& questions, const std::vector<LoggedUser>& users, const unsigned int id) :
	m_id(id)
{
	//beima shell Magshimimm hem lo yachloo la'asot meha'athala sheashe'elot yahzero bevector?
	for (Question question : questions)
		m_questions.push_back(question);

	for (LoggedUser user : users)
		m_players[user] = { 0,0,0,0 };
}

bool Game::removePlayer(const LoggedUser& user)
{
	return m_players.erase(user) == KEY_FOUND_IN_MAP;
}

int Game::getId() const
{
	return m_id;
}
