#include"../Databases/SQLiteDatabase.h"
#include<io.h>
#include<string>
#include<iostream>
#include"../Databases/SQLiteCallbacks.h"

#define ANS_LIMIT 4

SQLiteDatabase::SQLiteDatabase() {
	_errMessage = nullptr;
	bool isNewDB = _access(DATABASE_FILENAME, DOES_EXIST) == NOT_EXIST;

	if (sqlite3_open(DATABASE_FILENAME, &_db) != SQLITE_OK) {
		_db = nullptr;

		throw std::exception("Failed to open DB");
	}

	if (isNewDB) {
		initDatabase();
		testDatabase();
	}
}

SQLiteDatabase::~SQLiteDatabase() {
	sqlite3_close(_db);
	_db = nullptr;
}


bool SQLiteDatabase::doesUserExists(const std::string& name) {
	std::string sqlStatement;
	bool doesExists = false;

	sqlStatement = "SELECT * FROM USERS WHERE NAME='" + name + "';";
	if (sqlite3_exec(_db, sqlStatement.c_str(), doesExistCallback, &doesExists, &_errMessage) != SQLITE_OK)
		throw std::exception(_errMessage);

	return doesExists;
}

bool SQLiteDatabase::doesPasswordMatch(const std::string& name, const std::string& password) {
	std::string sqlStatement;
	bool doesMatch = false;

	sqlStatement = "SELECT * FROM USERS WHERE NAME='" + name + "' AND PASSWORD='" + password + "';";
	if (sqlite3_exec(_db, sqlStatement.c_str(), doesExistCallback, &doesMatch, &_errMessage) != SQLITE_OK)
		throw std::exception(_errMessage);

	return doesMatch;
}

void SQLiteDatabase::addNewUser(const std::string& name, const std::string& password, const std::string& mail) {
	std::string sqlStatement;
	sqlStatement = "INSERT INTO USERS (NAME, PASSWORD, MAIL) VALUES ('" + name + "', '" + password + "', '" + mail + "');";

	executeAndValidate(sqlStatement);
}

void SQLiteDatabase::addNewQuestion(const Question& q) {
	std::string sqlStatement;
	sqlStatement = "INSERT INTO QUESTIONS (QUESTION, RIGHT_ANS, ANS_1, ANS_2, ANS_3) VALUES('"
		+ q.getQuestion() + "', '" + q.getCorrectAnswer();

	for (std::string ans : q.getPossibleAnswers())
		if (ans != q.getCorrectAnswer())
			sqlStatement += "', '" + ans;
	sqlStatement += "');";

	executeAndValidate(sqlStatement);
}

std::list<Question> SQLiteDatabase::getQuestions(const int limit) {
	std::list<Question> out;
	std::string sqlStatement = "SELECT * FROM QUESTIONS";
	if (limit > 0)
		sqlStatement += " LIMIT " + std::to_string(limit);
	sqlStatement += ";";
	executeAndValidate(sqlStatement, &out, questionCallback);
	return out;
}

std::string SQLiteDatabase::getPlayerAverageAnswerTime(const std::string& name) {
	std::string averageAnswerTime;
	std::string sqlStatement;
	sqlStatement = "SELECT CAST(ANSWER_TIME_SECONDS AS float) / TOTAL_ANSWERS FROM STATISTICS WHERE USERNAME = '" + name + "';";
	executeAndValidate(sqlStatement, &averageAnswerTime, getOneNumberAsStringCallback);

	return averageAnswerTime;
}

std::string SQLiteDatabase::getNumOfCorrectAnswers(const std::string& name) {
	std::string correctAnswers;
	std::string sqlStatement;
	sqlStatement = "SELECT CORRECT_ANSWERS FROM STATISTICS WHERE USERNAME = '" + name + "';";
	executeAndValidate(sqlStatement, &correctAnswers, getOneNumberAsStringCallback);

	return correctAnswers;
}

std::string SQLiteDatabase::getNumOfTotalAnswers(const std::string& name) {
	std::string totalAnswers;
	std::string sqlStatement;
	sqlStatement = "SELECT TOTAL_ANSWERS FROM STATISTICS WHERE USERNAME = '" + name + "';";
	executeAndValidate(sqlStatement, &totalAnswers, getOneNumberAsStringCallback);

	return totalAnswers;
}

std::string SQLiteDatabase::getNumOfPlayerGames(const std::string& name) {
	std::string games;
	std::string sqlStatement;
	sqlStatement = "SELECT NUM_OF_GAMES FROM STATISTICS WHERE USERNAME = '" + name + "';";
	executeAndValidate(sqlStatement, &games, getOneNumberAsStringCallback);

	return games;
}

std::vector<std::string> SQLiteDatabase::getTopRatedUsers(const int numberOfUsers)
{
	std::vector<std::string> topUsers;
	std::string sqlStatement;
	sqlStatement = "SELECT USERNAME FROM STATISTICS ORDER BY (CORRECT_ANSWERS / TOTAL_ANSWERS) DESC LIMIT " + std::to_string(numberOfUsers);
	executeAndValidate(sqlStatement, &topUsers, getTopRatedUserCallback);

	return topUsers;
}


//private functions
void SQLiteDatabase::executeAndValidate(const std::string& sqlStatement) {
	if (sqlite3_exec(_db, sqlStatement.c_str(), nullptr, nullptr, &_errMessage) != SQLITE_OK)
		throw std::exception(_errMessage);
}

void SQLiteDatabase::executeAndValidate(const std::string& sqlStatement, void* data, int(*callback)(void*, int, char**, char**)) {
	if (sqlite3_exec(_db, sqlStatement.c_str(), callback, data, &_errMessage) != SQLITE_OK)
		throw std::exception(_errMessage);
}

void SQLiteDatabase::initDatabase() {
	std::string sqlStatement = "CREATE TABLE USERS (NAME TEXT PRIMARY KEY NOT NULL, PASSWORD TEXT NOT NULL, MAIL TEXT NOT NULL);";
	sqlStatement += "CREATE TABLE QUESTIONS (ID INTEGER PRIMARY KEY NOT NULL, QUESTION TEXT NOT NULL, RIGHT_ANS TEXT NOT NULL, ANS_1 TEXT NOT NULL, ANS_2 TEXT NOT_NULL, ANS_3 TEXT NOT_NULL);";
	sqlStatement += "CREATE TABLE STATISTICS (USERNAME TEXT PRIMARY KEY NOT NULL, TOTAL_ANSWERS INTEGER NOT NULL, CORRECT_ANSWERS INTEGER NOT NULL, ANSWER_TIME_SECONDS INTEGER NOT NULL, NUM_OF_GAMES INTEGER NOT NULL);";
	executeAndValidate(sqlStatement.c_str());

	this->addNewQuestion(Question("What is the answer to the question of the universe?", { "42", "12", "6*9", "666" }));
	this->addNewQuestion(Question("Why?", { "Llama", "Ok", "Becuase", "Something" }));
	this->addNewQuestion(Question("Who is the best?", { "Yerucham", "Yuda", "Froylich", "Ori" }));
	this->addNewQuestion(Question("How?", { "Like so and so", "Like that", "Not like so", "Banana" }));
	this->addNewQuestion(Question("4*5", { "20", "1", "-7.3", "12334" }));
	this->addNewQuestion(Question("5-1", { "4", "90", "203", "54" }));
	this->addNewQuestion(Question("9+0", { "9", "10", "90", "0" }));
	this->addNewQuestion(Question("0^0", { "1", "-8", "0", "Not Defined" }));
	this->addNewQuestion(Question("5+5", { "10", "-16", "21", "Batman" }));
	this->addNewQuestion(Question("Conventziot?", { "I like Linux and Injeras!", "Maybe?", "Yes... Clion is the best!", "No!!!!" }));
}

void SQLiteDatabase::testDatabase() {
	this->addNewUser("user1", "123", "user1@shovinism.com");
	this->addNewUser("user2", "456", "user2@homofobism.com");

	std::cout << "does passwords match? (yes): " << this->doesPasswordMatch("user1", "123") << "\n";
	std::cout << "does passwords match? (no): " << this->doesPasswordMatch("user1", "456") << "\n";

	std::cout << "does user exists? (yes): " << this->doesUserExists("user2") << "\n";
	std::cout << "does user exists? (no): " << this->doesUserExists("user 2") << "\n";
}