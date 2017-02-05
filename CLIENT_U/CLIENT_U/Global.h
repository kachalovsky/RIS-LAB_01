#pragma once
#include "GetSinchro.h"
#include "SetSinchro.h"
#include <iostream>
#include "Constants.h"

#include "SinchroInstance.h"

SinchroInstance sinchroManager;

GetSinchro * request = new GetSinchro();
SetSinchro * responce = new SetSinchro();

SOCKADDR_IN serverConfig;
int szServerConfig = sizeof(serverConfig);

void init(
	const char requestCommand[] = DEFAULT_REQUEST_COMMAND,
	const char ip[] = DEFAULT_SERVER_IP,
	const int port = DEFAULT_PORT
	)
{
	strcpy_s(request->cmd, requestCommand);

	serverConfig.sin_family = AF_INET;
	serverConfig.sin_port = htons(port);
	serverConfig.sin_addr.s_addr = inet_addr(ip);
	
}