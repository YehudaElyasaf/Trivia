#include"SQLiteDatabase.h"
#include<io.h>
#include<string>
#include<iostream>
#include"SQLiteCallbacks.h"

#define ANS_LIMIT 4

SQLiteDatabase::SQLiteDatabase() {
	_errMessage = nullptr;
	bool isNewDB = _access(DATABASE_FILENAME, DOES_EXIST) == NOT_EXIST;

	if (sqlite3_open(DATABASE_FILENAME, &_db) != SQLITE_OK) {
		_db = nullptr;

		throw std::exception("Failed to open DB");
	}

	if (isNewDB) {
		std::string sqlStatement = "CREATE TABLE USERS (NAME TEXT PRIMARY KEY NOT NULL, PASSWORD TEXT NOT NULL, MAIL TEXT NOT NULL);";
		sqlStatement += "CREATE TABLE QUESTIONS (ID INTEGER PRIMARY KEY NOT NULL, QUESTION TEXT NOT NULL, RIGHT_ANS TEXT NOT NULL, ANS_1 TEXT, ANS_2 TEXT, ANS_3 TEXT);";
		executeAndValidate(sqlStatement.c_str());

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
	sqlStatement = "INSERT INTO QUESTIONS (QUESTION, RIGHT_ANS";
	// starts at 1 because in the sql it is from 1 to 3, and the maximum of possible wrong answers is 3
	for (int i = 1; i < q.getPossibleAnswers().size() && i < ANS_LIMIT; i++)
		sqlStatement += ", ANS_" + std::to_string(i);
	
	sqlStatement += ") VALUES('" + q.getQuestion() + "', '" + q.getCorrectAnswer();
	
	for (std::string ans : q.getPossibleAnswers())
		if (ans != q.getCorrectAnswer())
			sqlStatement += "', '" + ans;
	sqlStatement += "');";

	executeAndValidate(sqlStatement);
}

//private functions
void SQLiteDatabase::executeAndValidate(const std::string& sqlStatement) {
	if (sqlite3_exec(_db, sqlStatement.c_str(), nullptr, nullptr, &_errMessage) != SQLITE_OK)
		throw std::exception(_errMessage);
}

void SQLiteDatabase::testDatabase() {
	this->addNewUser("user1", "123", "user1@shovinism.com");
	this->addNewUser("user2", "456", "user2@homofobism.com");

	this->addNewQuestion(Question("What is the answer to the question of the universe?", { "42", "12", "6*9", "666" }));
	this->addNewQuestion(Question("Why?", { "Llama", "Ok", "Becuase", "Something" }));
	this->addNewQuestion(Question("Who is the best?", { "Yerucham", "Yuda", "Froylich", "Ori" }));
	this->addNewQuestion(Question("How?", { "Like so and so", "Like that", "Not like so", "Banana" }));
	this->addNewQuestion(Question("4*5", { "20", "1", "-7.3", "12334" }));
	this->addNewQuestion(Question("5-1", { "4", "90", "203", "54" }));
	this->addNewQuestion(Question("9+0", { "9", "10", "90", "0" }));
	this->addNewQuestion(Question("0^0", { "1", "-8", "0", "Not Defined" }));
	this->addNewQuestion(Question("5+5", { "10", "-16", "21", "Batman" }));
	this->addNewQuestion(Question("Conventziot?", { "No!!!!", "Maybe?", "Yes... Clion's the best!", "I like Linux and Injeras!" }));

	std::cout << "does passwords match? (yes): " << this->doesPasswordMatch("user1", "123") << "\n";
	std::cout << "does passwords match? (no): " << this->doesPasswordMatch("user1", "456") << "\n";

	std::cout << "does user exists? (yes): " << this->doesUserExists("user2") << "\n";
	std::cout << "does user exists? (no): " << this->doesUserExists("user 2") << "\n";
}