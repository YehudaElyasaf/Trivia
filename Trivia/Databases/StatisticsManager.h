#pragma once
#include"../Databases/IDatabase.h"
#include<vector>
#include<string>

class StatisticsManager {
public:
    //c'tor
    StatisticsManager(IDatabase* db);
    //returns the 5 top rated users.
    //the rate is(numberOfCorrectAnswers / numberOfTotalAnswers)
    std::vector<std::string> getHighScore();
    
    /*
    return a vector with the user's statistics
    * vector values:
    * [0] - average answer time
    * [1] - number of correct answers
    * [2] - number of total answers
    * [3] - number of games of user
    */
    std::vector<std::string> getUserStatistics(const std::string& username);
private:
    IDatabase* m_database;
};
