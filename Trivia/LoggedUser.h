#include<vector>
#include<string>

class LoggedUser {
public:
	std::string getUserName() const;
private:
	std::string m_username;
};
