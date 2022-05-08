#pragma once
#include"sqlite3.h"
#include"IDatabase.h"
#include "Question.h"

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
	bool doesUserExists(const std::string& name) override;
	//check the if the password is correct
	bool doesPasswordMatch(const std::string& name, const std::string& password) override;
	//add a user to table
	void addNewUser(const std::string& name, const std::string& password, const std::string& mail) override;
	
	// add a question to table
	void addNewQuestion(const Question& q);

private:
	sqlite3* _db;
	char* _errMessage;

	//execute sql statement
	//and throw an exception in case of failture
	void executeAndValidate(const std::string& sqlStatement);

	//auto create a database 
	void testDatabase();
};