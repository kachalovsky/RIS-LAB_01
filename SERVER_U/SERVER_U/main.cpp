#include "GetSinchro.h"
#include "SetSinchro.h"
#include "Global.h"
#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

void sendToClient(int correction)
{
	responce->correction = correction;
	sinchroManager->sendSinchro(responce, &clientConfig, szClientConfig);
}

int getCurvalue()
{
	sinchroManager->getSinchro(request, &clientConfig, szClientConfig);
	return request->curvalue;
}

void main(int argc, char *argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	int Tc = (argc > 1)? atoi(argv[1]): 1000000;
	try {
		init();
		for (int i = 0; i < 10; i++)
		{

			cout << getCurvalue() << endl; //get current value from client

			sendToClient(50);//sending correction 50 to client	

			cout << i << " " <<
				"IP: " << inet_ntoa(clientConfig.sin_addr) <<
				":" << ntohs(clientConfig.sin_port) << endl;//
		}
	}
	catch (string errorMsg)
	{
		cout << errorMsg << endl;
	}
}