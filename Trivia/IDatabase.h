#pragma once

#include <string>

class IDatabase {
public:
	virtual bool doesUserExists(std::string name) = 0;
	virtual bool doesPasswordMatch(std::string name, std::string password) = 0;
	// change last string to what it needs to be
	virtual bool addNewUser(std::string name, std::string password, std::string s) = 0;
};

