#include"../Login/LoggedUser.h"

LoggedUser::LoggedUser(const std::string& name) {
	m_username = name;
}

bool operator==(const LoggedUser& user1, const LoggedUser& user2)
{
	return user1.m_username == user2.m_username;
}
