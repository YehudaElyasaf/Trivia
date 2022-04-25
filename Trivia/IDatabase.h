#pragma once

#include <string>

class IDatabase {
public:
	//ask the database if a user exists
	const virtual bool doesUserExists(const std::string& name) = 0;
	//check the if the password is correct
	const virtual bool doesPasswordMatch(const std::string& name, const std::string& password) = 0;
	//add a user to table
	const virtual void addNewUser(const std::string& name, const std::string& password, const std::string& mail) = 0;
};

