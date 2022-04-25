#include"sqlite3.h"
#include"SQLiteDatabase.h"
#include<io.h>
#include<string>
#include<iostream>
#include"SQLiteCallbacks.h"

SQLiteDatabase::SQLiteDatabase() {
	_errMessage = nullptr;
	bool isNewDB = _access(DATABASE_FILENAME, DOES_EXIST) == NOT_EXIST;

	if (sqlite3_open(DATABASE_FILENAME, &_db) != SQLITE_OK) {
		_db = nullptr;

		throw std::exception("Failed to open DB");
	}

	if (isNewDB)
		std::cout << "opened a new database!";
	else
		std::cout << "opened an existing database!";

	if (isNewDB) {
		char sqlStatement[] = "CREATE TABLE USERS (NAME TEXT PRIMARY KEY NOT NULL, PASSWORD TEXT NOT NULL, MAIL TEXT NOT NULL);";;
		executeAndValidate(sqlStatement);
	}
}

SQLiteDatabase::~SQLiteDatabase() {
	sqlite3_close(_db);
	_db = nullptr;
}


const bool SQLiteDatabase::doesUserExists(const std::string& name) {
	std::string sqlStatement;
	bool doesExists = false;

	sqlStatement = "SELECT * FROM USERS WHERE NAME='" + name + "';";
	if (sqlite3_exec(_db, sqlStatement.c_str(), doesExistCallback, &doesExists, &_errMessage) != SQLITE_OK)
		throw std::exception(_errMessage);

	return doesExists;
}

const bool SQLiteDatabase::doesPasswordMatch(const std::string& name, const std::string& password) {
	std::string sqlStatement;
	bool doesMatch = false;

	sqlStatement = "SELECT FROM USERS WHERE NAME='" + name + "' AND PASSWORD='" + password + "';";
	if (sqlite3_exec(_db, sqlStatement.c_str(), doesExistCallback, &doesMatch, &_errMessage) != SQLITE_OK)
		throw std::exception(_errMessage);

	return doesMatch;
}

const void SQLiteDatabase::addNewUser(const std::string& name, const std::string& password, const std::string& mail) {
	std::string sqlStatement;
	sqlStatement = "INSERT INTO USERS (NAME, PASSWORD, MAIL) VALUES ('" + name + "', '" + password + "', '" + mail + "');";

	executeAndValidate(sqlStatement);
}

//private functions
void SQLiteDatabase::executeAndValidate(const std::string& sqlStatement) {
	if (sqlite3_exec(_db, sqlStatement.c_str(), nullptr, nullptr, &_errMessage) != SQLITE_OK)
		throw std::exception(_errMessage);
}