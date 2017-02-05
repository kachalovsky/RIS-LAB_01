#pragma once

#include "GetSinchro.h"
#include "SetSinchro.h"

#include <WinSock2.h>
#pragma comment(lib,"WS2_32.lib")

#include <Windows.h> 


class SinchroInstance {
public:	

	SOCKET serverSocket;

	SinchroInstance(SOCKADDR_IN* serverConfig);
	~SinchroInstance();

	void sendSinchro(SetSinchro* request, SOCKADDR_IN* serverConfig, int szServerConfig);
	void getSinchro(GetSinchro* responce, SOCKADDR_IN* serverConfig, int szServerConfig);

private:
	WSAData wsa;
};