#pragma once
#pragma comment(lib, "ws2_32.lib")
#include <WinSock2.h>
#include <Windows.h>

#define SOCKET_VERSION MAKEWORD(2, 2)

class WSAInitializer
{
public:
	WSAInitializer();
	~WSAInitializer();
};

