#pragma once

#include <string>
#include <list>
#include "Question.h"

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
	virtual float getPlayerAverageAnswerTime(const std::string& name) = 0;
	virtual int getNumOfCorrectAnswers(const std::string& name) = 0;
	virtual int getNumOfTotalAnswers(const std::string& name) = 0;
	virtual int getNumOfPlayerGames(const std::string& name) = 0;
};

