#include"Room.h"

//must have a default c'tor
Room::Room() {}

Room::Room(const LoggedUser& firstUser, const RoomData& roomData) : m_roomdata(roomData)
{
	m_users.push_back(firstUser);
}

bool Room::addUser(const LoggedUser& userToAdd) {
	if (std::find(m_users.begin(), m_users.end(), userToAdd) != m_users.end())
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
