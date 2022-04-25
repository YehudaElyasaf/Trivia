#include"SQLiteCallbacks.h"

int doesExistCallback(void* data, int argc, char** argv, char** azColumnName) {
	bool* pDoesExist = (bool*)data;
	*pDoesExist = true;

	return 0;
}