#include"sqlite3.h"
#include"SQLiteDatabase.h"
#include<io.h>
#include<string>
#include<iostream>

SQLiteDatabase::SQLiteDatabase() {
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
		char* errMessage;
		char sqlStatement[] = "CREATE TABLE USERS (NAME TEXT PRIMARY KEY NOT NULL, PASSWORD TEXT NOT NULL, MAIL TEXT NOT NULL);";;
		executeAndValidate(sqlStatement);
	}
}
SQLiteDatabase::~SQLiteDatabase() {
	sqlite3_close(_db);
	_db = nullptr;
}

const bool SQLiteDatabase::doesUserExists(const std::string& name) {

}
const bool SQLiteDatabase::doesPasswordMatch(const std::string& name, const std::string& password) {

}
const bool SQLiteDatabase::addNewUser(const std::string& name, const std::string& password, const std::string& mail) {

}

void SQLiteDatabase::executeAndValidate(const std::string& sqlStatement) {

}