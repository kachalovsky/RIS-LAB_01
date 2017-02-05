#pragma once

#include "GetSinchro.h"
#include "SetSinchro.h"

#include <WinSock2.h>
#pragma comment(lib,"WS2_32.lib")

#include <Windows.h> 


class SinchroInstance {
public:	

	SOCKET clientSocket;

	SinchroInstance();
	~SinchroInstance();

	void sendSinchro(GetSinchro* request, SOCKADDR_IN* serverConfig, int szServerConfig);
	void getSinchro(SetSinchro* responce, SOCKADDR_IN* serverConfig, int szServerConfig);

private:
	WSAData wsa;
};