#pragma once
#include<exception>

struct RoomNotFoundException : public std::exception
{
	const char* what() const throw ()
	{
		return "Room not found";
	}
};