#include "Question.h"
#include <algorithm>

Question::Question(const std::string& question, const std::vector<std::string>& possibleAnswers) {
    m_question = question;
    m_possibleAnswers = possibleAnswers;
}

std::string Question::getQuestion() const {
    return m_question;
}

std::vector<std::string> Question::getPossibleAnswers() const {
    std::vector<std::string> out = m_possibleAnswers;
    std::random_shuffle(out.begin(), out.end());
    return out;
}

std::string Question::getCorrectAnswer() const {
    return m_possibleAnswers[CORRECT_ANS];
}
