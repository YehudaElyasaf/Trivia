#pragma once
#include"../Databases/IDatabase.h"
#include"../Game/Game.h"
#include"../Room/Room.h"

class GameManager {
private:
	IDatabase* m_database;
	std::vector<Game> m_games;

public:
	GameManager(IDatabase* database);
	Game createGame(const Room& room);
	void deleteGame(const Game& game);
};