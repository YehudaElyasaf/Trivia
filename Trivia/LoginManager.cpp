#include "LoginManager.h"
#include"SQLiteDatabase.h"

LoginManager::LoginManager(IDatabase* database) {
	m_database = database;
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
	for (int i = 0; i < m_loggedUsers.size(); i++)
		if (m_loggedUsers[i].getUserName() == name) {
			m_loggedUsers.erase(m_loggedUsers.begin() + i);
			return true;
		}
}