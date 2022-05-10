#include"StatisticsManager.h"

#define NUMBER_OF_TOP_USERS 5

StatisticsManager::StatisticsManager(IDatabase* db)
 : m_database(db) {}
std::vector<std::string> StatisticsManager::getHighScore(){
    return m_database->getTopRatedUsers(NUMBER_OF_TOP_USERS);
}
std::vector<std::string> StatisticsManager::getUserStatistics(const std::string& username){
    std::vector<std::string> statistics;
    
    statistics.push_back(m_database->getPlayerAverageAnswerTime(username));
    statistics.push_back(m_database->getNumOfCorrectAnswers(username));
    statistics.push_back(m_database->getNumOfTotalAnswers(username));
    statistics.push_back(m_database->getNumOfPlayerGames(username));

    return statistics;
}
