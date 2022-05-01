#include "LoginManager.h"
#include"SQLiteDatabase.h"

LoginManager::LoginManager() {
	m_database = new SQLiteDatabase;
}

LoginManager::~LoginManager() {
	delete m_database;
}

bool LoginManager::signup(const std::string& name, const std::string& password, const std::string& mail) {
	if (!m_database->doesUserExists(name)) {
		m_database->addNewUser(name, password, mail);
		return true;
	}

	return false;
}

bool LoginManager::login(const std::string& name, const std::string& password) {
	if (m_database->doesPasswordMatch(name, password)) {
		m_loggedUsers.push_back(name);
		return true;
	}

	return false;
}

bool LoginManager::logout(const std::string& name) {

}