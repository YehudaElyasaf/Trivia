#include<vector>
#include<string>

struct LoggedUser {
public:
	LoggedUser(const std::string& name);
	std::string getUserName() const;
private:
	std::string m_username;
};
