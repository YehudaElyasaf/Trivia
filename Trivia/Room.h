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
    bool addUser(const LoggedUser& user);
    bool removeUser(const LoggedUser& user);
    std::vector<LoggedUser> getAllUsers() const;
private:
    RoomData m_metadata;
    std::vector<LoggedUser> m_users;
};
