#pragma once
#include<vector>
#include<string>

struct LoggedUser {
	std::string m_username;
	LoggedUser(const std::string& name);
	friend bool operator==(const LoggedUser& user1, const LoggedUser& user2);
	friend bool operator<(const LoggedUser& l, const LoggedUser& r);
};