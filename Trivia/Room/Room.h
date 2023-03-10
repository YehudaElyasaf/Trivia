#pragma once
#include<string>
#include<vector>
#include"../Login/LoggedUser.h"

struct RoomData
{
	unsigned int id = 0;
	std::string name = "";
	unsigned int maxPlayers = 0;
	unsigned int numOfQuestionsInGame = 0;
	unsigned int timePerQuestion = 0;
	bool isActive = false;
};

class Room
{
public:
	Room();
	Room(const LoggedUser& firstUser, const RoomData& roomData);
	bool addUser(const LoggedUser& userToAdd);
	bool removeUser(const LoggedUser& userToRemove);
	std::vector<LoggedUser> getAllUsers() const;
	RoomData& getRoomData();
private:
	RoomData m_roomdata;
	std::vector<LoggedUser> m_users;
};
