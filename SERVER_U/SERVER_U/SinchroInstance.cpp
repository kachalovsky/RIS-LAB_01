#include "SinchroInstance.h"
#include "Validation.h"

SinchroInstance::SinchroInstance(SOCKADDR_IN* serverConfig)
{
	if (WSAStartup(MAKEWORD(2, 0), &wsa) != 0)
		throw GetErrorMsg("WSA:", WSAGetLastError());

	if ((serverSocket = socket(AF_INET, SOCK_DGRAM, NULL)) == INVALID_SOCKET)
		throw GetErrorMsg("Socket:", WSAGetLastError());


	if ((bind(serverSocket, (LPSOCKADDR)serverConfig, sizeof(*serverConfig))) == SOCKET_ERROR)
		throw GetErrorMsg("Bind:", WSAGetLastError());

}

SinchroInstance::~SinchroInstance()
{
	closesocket(serverSocket);
	WSACleanup();
}

void SinchroInstance::sendSinchro(SetSinchro* responce, SOCKADDR_IN* clientConfig, int szClientConfig)
{
	if ((sendto(serverSocket, (char *)responce, sizeof(*responce), NULL, (LPSOCKADDR)clientConfig, szClientConfig)) == SOCKET_ERROR)
		throw GetErrorMsg("Send:", WSAGetLastError());
}

void SinchroInstance::getSinchro(GetSinchro* request, SOCKADDR_IN* clientConfig, int szClientConfig)
{
	memset(clientConfig, 0, sizeof(*clientConfig));
	if ((recvfrom(serverSocket, (char *)request, sizeof(*request), NULL, (LPSOCKADDR)clientConfig, &szClientConfig)) == SOCKET_ERROR)
		throw GetErrorMsg("Recv:", WSAGetLastError());
}
