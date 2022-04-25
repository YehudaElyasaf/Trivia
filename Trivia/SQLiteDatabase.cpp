#include"sqlite3.h"
#include"SQLiteDatabase.h"

#include<io.h>
#include<string>

SQLiteDatabase::SQLiteDatabase() {
	char* sqlStatements[] = { "","","","" };
	bool isNewDB = _access(DATABASE_FILENAME, DOES_EXIST) == NOT_EXIST;
}
SQLiteDatabase::~SQLiteDatabase() {
	
}

const bool SQLiteDatabase::doesUserExists(const std::string& name) {

}
const bool SQLiteDatabase::doesPasswordMatch(const std::string& name, const std::string& password) {

}
const bool SQLiteDatabase::addNewUser(const std::string& name, const std::string& password, const std::string& mail) {

}