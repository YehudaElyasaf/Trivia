#pragma once
#include"IDatabase.h"

#define DATABASE_FILENAME "DB.sqlite"
#define DOES_EXIST 0
#define NOT_EXIST -1

class SQLiteDatabase : public IDatabase {
public:
	//open DB
	SQLiteDatabase();
	//close DB
	~SQLiteDatabase();

	//ask the database if a user exists
	const bool doesUserExists(const std::string& name) override;
	//check the if the password is correct
	const bool doesPasswordMatch(const std::string& name, const std::string& password) override;
	//add a user to table
	const bool addNewUser(const std::string& name, const std::string& password, const std::string& mail) override;
};