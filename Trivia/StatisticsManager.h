#pragma once
#include"IDatabase.h"
#include<vector>
#include<string>

class StatisticsManager
{
public:
    StatisticsManager(IDatabase* db);
    std::vector<std::string> getHighScore();
    std::vector<std::string> getUserStatistics(const std::string& username);
private:
    IDatabase* m_database;
};
