#pragma once
#include<string>
#include<vector>
#include"LoggedUser.h"

struct RoomData
{
    unsigned int id;
    std::string name;
    unsigned int maxPlayers;
    unsigned int numOfQuestionsInGame;
    unsigned int timePerQuestion;
    bool isActivce;
};

class Room
{
public:
    Room(const LoggedUser& firstUser, const RoomData& roomData);
    bool addUser(const LoggedUser& userToAdd);
    bool removeUser(const LoggedUser& userToRemove);
    std::vector<LoggedUser> getAllUsers() const;
    RoomData getRoomData() const;
private:
    RoomData m_roomdata;
    std::vector<LoggedUser> m_users;
};
