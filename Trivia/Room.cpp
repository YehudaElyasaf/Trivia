#include"Room.h"

Room::Room(const LoggedUser& firstUser, const RoomData& roomData){
    m_users.push_back(firstUser);
    m_metadata = roomData;
}

bool Room::addUser(const LoggedUser& user){

}
bool Room::removeUser(const LoggedUser& user){

}

std::vector<LoggedUser> Room::getAllUsers() const{

}
