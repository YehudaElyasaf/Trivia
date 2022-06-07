#pragma once
#include"../Databases/IDatabase.h"
#include"../Game/Game.h"
#include"../Room/Room.h"

class GameManager {
private:
	IDatabase* m_database;
	std::map<unsigned int, Game> m_games;
	unsigned int m_nextId;

public:
	GameManager(IDatabase* database);
	Game createGame(const Room& room);
	bool deleteGame(const unsigned int id);
};