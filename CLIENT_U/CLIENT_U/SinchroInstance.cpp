#include "SinchroInstance.h"
#include "Validation.h"

SinchroInstance::SinchroInstance()
{
	if (WSAStartup(MAKEWORD(2, 0), &wsa) != 0)
		throw GetErrorMsg("WSA:", WSAGetLastError());

	if ((clientSocket = socket(AF_INET, SOCK_DGRAM, NULL)) == INVALID_SOCKET)
		throw GetErrorMsg("Socket:", WSAGetLastError());
}

SinchroInstance::~SinchroInstance()
{
	closesocket(clientSocket);
	WSACleanup();
}

void SinchroInstance::sendSinchro(GetSinchro* request, SOCKADDR_IN* serverConfig, int szServerConfig)
{
	if ((sendto(clientSocket, (char *)request, sizeof(*request), NULL, (LPSOCKADDR)serverConfig, szServerConfig)) == SOCKET_ERROR)
		throw GetErrorMsg("Send:", WSAGetLastError());
}

void SinchroInstance::getSinchro(SetSinchro* responce, SOCKADDR_IN* serverConfig, int szServerConfig)
{
	if ((recvfrom(clientSocket, (char *)responce, sizeof(*responce), NULL, (LPSOCKADDR)serverConfig, &szServerConfig)) == SOCKET_ERROR)
		throw GetErrorMsg("Recv:", WSAGetLastError());
}
