#pragma once
#include "../lib/sqlite3.h"
#include "../Databases/IDatabase.h"
#include "../Databases/Question.h"
#include <list>

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
	void addNewQuestion(const Question& q) override;
	// get (optional: a limited number of) all questions from the database
	std::list<Question> getQuestions(const int limit = UNLIMITED) override;
	std::string getPlayerAverageAnswerTime(const std::string& name) override;
	std::string getNumOfCorrectAnswers(const std::string& name) override;
	std::string getNumOfTotalAnswers(const std::string& name) override;
	std::string getNumOfPlayerGames(const std::string& name) override;
	//returns the top rated users.
	//the rate is (numberOfCorrectAnswers /numberOfTotalAnswers)
	std::vector<std::string> getTopRatedUsers(const int numberOfUsers) override;

private:
	sqlite3* _db;
	char* _errMessage;

	//execute sql statement
	//and throw an exception in case of failture
	void executeAndValidate(const std::string& sqlStatement);
	// execute and verify with callbacks
	void executeAndValidate(const std::string& sqlStatement, void* data, int(*callback)(void*, int, char**, char**));

	//auto create a database 
	void testDatabase();
};