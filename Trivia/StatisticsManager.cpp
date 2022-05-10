#include"StatisticsManager.h"

StatisticsManager::StatisticsManager(IDatabase* db)
 : m_database(db) {}
std::vector<std::string> StatisticsManager::getHighScore(){
    
}
std::vector<std::string> StatisticsManager::getUserStatistics(const std::string& username){
    std::vector<std::string> statistics;
    
    statistics.push_back(m_database->getPlayerAverageAnswerTime(username));
    statistics.push_back(m_database->getNumOfCorrectAnswers(username));
    statistics.push_back(m_database->getNumOfTotalAnswers(username));
    statistics.push_back(m_database->getNumOfPlayerGames(username));

    return statistics;
}
