#include"LoggedUser.h"
#include"IDatabase.h"
#include<string>
#include<vector>

class LoginManager {
public:
	//c'tor and d'tor
	LoginManager();
	~LoginManager();

	//add user to DB
	void signup(const std::string& name, const std::string& password, const std::string& mail);
	//add an exist user to logged users' vector
	void login(const std::string& name, const std::string& password);
	//remove an exist user to logged users' vector
	void logout(const std::string& name);

private:
	IDatabase* m_database;
	std::vector<LoggedUser> m_loggedUsers;
};
