#include "SQLiteCallbacks.h"
#include "Question.h"
#include <list>

int doesExistCallback(void* data, int argc, char** argv, char** azColumnName) {
	bool* pDoesExist = (bool*)data;
	*pDoesExist = true;

	return 0;
}

int questionCallback(void* data, int argc, char** argv, char** azColumnName) {
	std::list<Question>* questions = (std::list<Question>*)data;
	std::string question;
	std::vector<std::string> answers;


	for (int i = 0; i < argc; i++) {
		if (!strcmp(azColumnName[i], "ID"))
			continue;
		if (!strcmp(azColumnName[i], "QUESTION"))
			question = argv[i];
		// answers
		else
			answers.push_back(argv[i]);
	}

	questions->emplace_back(question, answers);

	return 0;
}

int getOneNumberFromDatabaseCallback(void* data, int argc, char** argv, char** azColumnName) {
	int* pNumber = (int*)data;
	*pNumber = std::stoi(argv[0]);

	return 0;
}