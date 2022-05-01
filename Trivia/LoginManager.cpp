#include "LoginManager.h"
#include"SQLiteDatabase.h"

LoginManager::LoginManager() {
	m_database = new SQLiteDatabase;
}

LoginManager::~LoginManager() {
	delete m_database;
}

void LoginManager::signup(const std::string& name, const std::string& password, const std::string& mail) {
	if (!m_database->doesUserExists(name))
		m_database->addNewUser(name, password, mail);
}

void LoginManager::login(const std::string& name, const std::string& password) {

}

void LoginManager::logout(const std::string& name) {

}