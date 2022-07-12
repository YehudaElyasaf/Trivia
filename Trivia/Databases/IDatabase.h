#pragma once

#include <string>
#include <list>
#include "../Game/Question.h"

#define UNLIMITED -1

class IDatabase {
public:
	//ask the database if a user exists
	virtual bool doesUserExists(const std::string& name) = 0;
	//check the if the password is correct
	virtual bool doesPasswordMatch(const std::string& name, const std::string& password) = 0;
	//add a user to table
	virtual void addNewUser(const std::string& name, const std::string& password, const std::string& mail) = 0;

	// add a question to database
	virtual void addNewQuestion(const Question& q) = 0;
	// get (optional: a limited number of) all questions from the database
	virtual std::list<Question> getQuestions(const int limit = UNLIMITED) = 0;

	//get and set to statistincs
	virtual std::string getPlayerAverageAnswerTime(const std::string& name) = 0;
	virtual std::string getNumOfCorrectAnswers(const std::string& name) = 0;
	virtual std::string getNumOfTotalAnswers(const std::string& name) = 0;
	virtual std::string getNumOfPlayerGames(const std::string& name) = 0;
	virtual std::vector<std::string> getTopRatedUsers(const int numberOfUsers) = 0;
	virtual void addToAnswerTime(const std::string& username, const unsigned int timeToAdd) = 0;
	virtual void addToCorrectAnswers(const std::string& username, const unsigned int correctAnswersToAdd) = 0;
	virtual void addToTotalAnswers(const std::string& username, const unsigned int answersToAdd) = 0;
	virtual void increaseTotalGames(const std::string& username) = 0;
};

