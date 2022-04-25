#pragma once
#include <string>

enum MsgCodes{ ERROR, LOGIN, SIGNUP };

struct LoginResponse {
	unsigned int status;
};

struct SignupResponse {
	unsigned int status;
};

struct ErrorResponse {
	std::string message;
};