#include"Room.h"

Room::Room(const LoggedUser& firstUser, const RoomData& roomData){
    m_users.push_back(firstUser);
    m_metadata = roomData;
}

bool Room::addUser(const LoggedUser& userToAdd){
    for (LoggedUser user : m_users)
        if (user == userToAdd)
            return false;

    m_users.push_back(userToAdd);
    return true;
}
bool Room::removeUser(const LoggedUser& user){

}

std::vector<LoggedUser> Room::getAllUsers() const{
    return m_users;
}
