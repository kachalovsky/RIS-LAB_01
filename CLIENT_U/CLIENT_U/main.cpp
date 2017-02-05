#include "GetSinchro.h"
#include "SetSinchro.h"
#include "Global.h"
#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

void sendToServer(int curvalue)
{
	request->curvalue = curvalue;
	sinchroManager.sendSinchro(request, &serverConfig, szServerConfig);
}

int getCorrection()
{
	sinchroManager.getSinchro(responce, &serverConfig, szServerConfig);
	return responce->correction;
}

void main(int argc, char *argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	int Tc = (argc > 1)? atoi(argv[1]): 1000000;
	try {
		init();
		for (int i = 0; i < 10; i++, Sleep(Tc / 1000))
		{
			sendToServer(i);//send current value to server

			cout << getCorrection() << endl;//get correction from server
			
		}
	}
	catch (string errorMsg)
	{
		cout << errorMsg << endl;
	}
}