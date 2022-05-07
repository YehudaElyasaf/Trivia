#include"Room.h"

Room::Room(const LoggedUser& firstUser, const RoomData& roomData) {
	m_users.push_back(firstUser);
	m_roomdata = roomData;
}

bool Room::addUser(const LoggedUser& userToAdd) {
	for (LoggedUser user : m_users)
		if (user == userToAdd)
			return false;

	m_users.push_back(userToAdd);
	return true;
}
bool Room::removeUser(const LoggedUser& userToRemove) {
	for (int i = 0; i < m_users.size(); i++)
		if (m_users[i] == userToRemove) {
			m_users.erase(m_users.begin() + i);
			return true;
		}

	return false;
}

std::vector<LoggedUser> Room::getAllUsers() const {
	return m_users;
}

RoomData Room::getRoomData() const
{
	return m_roomdata;
}
