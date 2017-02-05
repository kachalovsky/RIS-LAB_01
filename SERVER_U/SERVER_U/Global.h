#pragma once
#include "GetSinchro.h"
#include "SetSinchro.h"
#include <iostream>
#include "Constants.h"

#include "SinchroInstance.h"

SinchroInstance * sinchroManager;

GetSinchro * request = new GetSinchro();
SetSinchro * responce = new SetSinchro();

SOCKADDR_IN serverConfig;
SOCKADDR_IN clientConfig;

int szServerConfig = sizeof(serverConfig);
int szClientConfig = sizeof(clientConfig);


void init(
	const char requestCommand[] = DEFAULT_REQUEST_COMMAND,
	const int port = DEFAULT_PORT
	)
{
	strcpy_s(responce->cmd, requestCommand);

	serverConfig.sin_family = AF_INET;
	serverConfig.sin_port = htons(port);
	serverConfig.sin_addr.s_addr = INADDR_ANY;
	sinchroManager = new SinchroInstance(&serverConfig);
}