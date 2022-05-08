#pragma once
#include <string>
#include <vector>

#define CORRECT_ANS 0

class Question {
public:
	// FIRST ANSWER IS THE CORRECT ONE!!
	Question(const std::string& question, const std::vector<std::string>& possibleAnswers);

	std::string getQuestion() const;
	// returns shuffled possible answers
	std::vector<std::string>& getPossibleAnswers() const;
	std::string getCorrectAnswer() const;

private:
	std::string m_question;
	std::vector<std::string> m_possibleAnswers;
};