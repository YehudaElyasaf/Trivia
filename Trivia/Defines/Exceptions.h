#pragma once
#include<exception>

struct RoomNotFoundException : public std::exception
{
	const char* what() const throw ()
	{
		return "Room not found";
	}
};

struct NoUsernameException : public std::exception
{
	const char* what() const throw ()
	{
		return "this request handler has no field 'username'";
	}
};