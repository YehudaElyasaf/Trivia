#include "../Communication/Helper.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>

// recieve data from socket according byteSize
// returns the data as string
std::string Helper::getStringPartFromSocket(const SOCKET sc, const int bytesNum)
{
	return getPartFromSocket(sc, bytesNum, 0);
}

// return string after padding zeros if necessary
std::string Helper::getPaddedNumber(const int num, const int digits)
{
	std::ostringstream ostr;
	ostr << std::setw(digits) << std::setfill('0') << num;
	return ostr.str();

}

// recieve data from socket according byteSize
// this is private function
std::string Helper::getPartFromSocket(const SOCKET sc, const int bytesNum)
{
	return getPartFromSocket(sc, bytesNum, 0);
}

// send data to socket
// this is private function
void Helper::sendData(const SOCKET sc, const std::string message)
{
	const char* data = message.c_str();

	if (send(sc, data, message.size(), 0) == INVALID_SOCKET)
	{
		throw std::exception("Error while sending message to client");
	}
}

std::string Helper::getPartFromSocket(const SOCKET sc, const int bytesNum, const int flags)
{
	if (bytesNum == 0)
	{
		return "";
	}

	char* data = new char[bytesNum + 1];
	int res = recv(sc, data, bytesNum, flags);
	data[bytesNum] = 0;
	if (res == INVALID_SOCKET)
	{
		std::string s = "Error while recieving from socket: ";
		s += std::to_string(sc);
		throw std::exception(s.c_str());
	}
	std::string received(data);
	delete[] data;
	return received;
}

int Helper::getDataLengthFromSockect(const SOCKET sock) {

	// if there are 0's on the back it won't get it because it's a string,
	// so im adding to it until it's size of int + 1
	std::string lastMsg = Helper::getStringPartFromSocket(sock, MESSAGE_LENGTH_FIELD_LENGTH);
	while (lastMsg.size() < MESSAGE_LENGTH_FIELD_LENGTH)
		lastMsg += '\0';

	// convert length bytes to int
	int dataLen = 0;
	*(&dataLen) = *((int*)lastMsg.c_str());

	return dataLen;
}
