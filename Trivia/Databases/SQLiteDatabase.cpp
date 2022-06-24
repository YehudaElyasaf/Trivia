#include"../Databases/SQLiteDatabase.h"
#include<io.h>
#include<string>
#include<iostream>
#include"../Databases/SQLiteCallbacks.h"

#define ANS_LIMIT 4
#define EMPTY_VALUE "---"

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

	sqlStatement = "INSERT INTO STATISTICS (USERNAME, TOTAL_ANSWERS, CORRECT_ANSWERS, ANSWER_TIME_SECONDS, NUM_OF_GAMES) VALUES ('" + name + "', 0, 0, 0, 0);";

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
	std::string sqlStatement = "SELECT * FROM QUESTIONS ORDER BY RANDOM()";
	if (limit > 0)
		sqlStatement += " LIMIT " + std::to_string(limit);
	sqlStatement += ";";
	executeAndValidate(sqlStatement, &out, questionCallback);
	return out;
}

std::string SQLiteDatabase::getPlayerAverageAnswerTime(const std::string& name) {
	std::string averageAnswerTime = EMPTY_VALUE;
	std::string sqlStatement;
	sqlStatement = "SELECT CAST(ANSWER_TIME_SECONDS AS float) / TOTAL_ANSWERS FROM STATISTICS WHERE USERNAME = '" + name + "';";
	executeAndValidate(sqlStatement, &averageAnswerTime, getOneNumberAsStringCallback);

	return averageAnswerTime;
}

std::string SQLiteDatabase::getNumOfCorrectAnswers(const std::string& name) {
	std::string correctAnswers = EMPTY_VALUE;
	std::string sqlStatement;
	sqlStatement = "SELECT CORRECT_ANSWERS FROM STATISTICS WHERE USERNAME = '" + name + "';";
	executeAndValidate(sqlStatement, &correctAnswers, getOneNumberAsStringCallback);

	return correctAnswers;
}

std::string SQLiteDatabase::getNumOfTotalAnswers(const std::string& name) {
	std::string totalAnswers = EMPTY_VALUE;
	std::string sqlStatement;
	sqlStatement = "SELECT TOTAL_ANSWERS FROM STATISTICS WHERE USERNAME = '" + name + "';";
	executeAndValidate(sqlStatement, &totalAnswers, getOneNumberAsStringCallback);

	return totalAnswers;
}

std::string SQLiteDatabase::getNumOfPlayerGames(const std::string& name) {
	std::string games = EMPTY_VALUE;
	std::string sqlStatement;
	sqlStatement = "SELECT NUM_OF_GAMES FROM STATISTICS WHERE USERNAME = '" + name + "';";
	executeAndValidate(sqlStatement, &games, getOneNumberAsStringCallback);

	return games;
}

std::vector<std::string> SQLiteDatabase::getTopRatedUsers(const int numberOfUsers)
{
	std::vector<std::string> topUsers;
	std::string sqlStatement;
	sqlStatement = "SELECT USERNAME FROM STATISTICS ORDER BY (CORRECT_ANSWERS / TOTAL_ANSWERS) DESC LIMIT " + std::to_string(numberOfUsers) + ";";
	executeAndValidate(sqlStatement, &topUsers, getTopRatedUserCallback);

	return topUsers;
}

void SQLiteDatabase::addToAnswerTime(const std::string& username, const unsigned int timeToAdd) {
	std::string sqlStatement;
	sqlStatement = "UPDATE STATISTICS SET ANSWER_TIME_SECONDS = ANSWER_TIME_SECONDS + " + std::to_string(timeToAdd) + " WHERE USERNAME = '" + username + "';";
	executeAndValidate(sqlStatement);
}

void SQLiteDatabase::addToCorrectAnswers(const std::string& username, const unsigned int correctAnswersToAdd) {
	std::string sqlStatement;
	sqlStatement = "UPDATE STATISTICS SET CORRECT_ANSWERS = CORRECT_ANSWERS + " + std::to_string(correctAnswersToAdd) + " WHERE USERNAME = '" + username + "';";
	executeAndValidate(sqlStatement);
}

void SQLiteDatabase::addToTotalAnswers(const std::string& username, const unsigned int answersToAdd) {
	std::string sqlStatement;
	sqlStatement = "UPDATE STATISTICS SET TOTAL_ANSWERS = TOTAL_ANSWERS + " + std::to_string(answersToAdd) + " WHERE USERNAME = '" + username + "';";
	executeAndValidate(sqlStatement);
}

void SQLiteDatabase::increaseTotalGames(const std::string& username)
{
	std::string sqlStatement;
	sqlStatement = "UPDATE STATISTICS SET NUM_OF_GAMES = NUM_OF_GAMES + 1 WHERE USERNAME = '" + username + "';";
	executeAndValidate(sqlStatement);
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
	this->addNewQuestion(Question("Which is the most interesting Masechet?", { "Makot", "Mishna", "Kodashim", "Yesodey Hatorah" }));
	this->addNewQuestion(Question("What is the name of froilich?", { "Al", "Aliyahoo", "AI", "AL" }));
	this->addNewQuestion(Question("Which is the best gender?", { "There is no such thing \"gender\"", "bisexual", "female", "homosexual" }));
	this->addNewQuestion(Question("Which comes before: private or public?", { "private", "public", "depending on the programming langauge", "it does not matter" }));
	this->addNewQuestion(Question("What is the value of G?", { "6.67 * 10^-11 m^3*kg^-1*sec^-2", "1 kg * m * sec^-2", "10N (Newtons)", "G is not constant" }));
	this->addNewQuestion(Question("The last words of Pythagoras were...", { "Do not touch my circles!","eureka","nobody knows","Heil Hitler!" }));
	this->addNewQuestion(Question("How did Muhamad die?", { "he did not","in a car crash","he fell of his unicorn","he was very old" }));
	this->addNewQuestion(Question("What is the meaning of life?", { "life has no meaning","life has no meaning.","life has no meaning!","life has no meaning!!!" })); //purposely the same
	this->addNewQuestion(Question("just guess the answer", { "1","2","3","4" }));
	this->addNewQuestion(Question("Who is called \"King David\"?", { "King David","Yosi Yafe","Many peoples","David Yurman" }));
	this->addNewQuestion(Question("2 + 2 * 2 = ?", { "6","8","0","Math Error" }));
	this->addNewQuestion(Question("Itetey itetey are...", { "amtahta deachnaey","go to the kitchen","useless","inferior" }));
}

void SQLiteDatabase::testDatabase() {
	this->addNewUser("1", "1", "user1@shovinism.com");
	this->addNewUser("2", "2", "user2@homofobism.com");
	this->addNewUser("3", "3", "user2@shovinism.com");
	this->addNewUser("4", "4", "user4@homofobism.com");
	this->addNewUser("5", "5", "user5@homofobism.com");
}
