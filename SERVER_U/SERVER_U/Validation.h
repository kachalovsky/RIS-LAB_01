#pragma once
#include <Winsock2.h>
#include <string>
using namespace std;

string GetErrorSocketMsgByCode(int code)
{
	string msg = "";
	switch (code)
	{
	case WSAEINTR: msg = "������ ������� ��������"; break;
	case WSAEACCES: msg = "���������� ����������"; break;
	case WSAEFAULT: msg = "��������� �����"; break;
	case WSAEINVAL: msg = "������ � ���������"; break;
	case WSAEMFILE: msg = "������� ����� ������ �������"; break;
	case WSAEWOULDBLOCK: msg = "������ �������� ����������"; break;
	case WSAEINPROGRESS: msg = "�������� � �������� ��������"; break;
	case WSAEALREADY: msg = "�������� ��� �����������"; break;
	case WSAENOTSOCK: msg = "����� ����� �����������"; break;
	case WSAEDESTADDRREQ: msg = "��������� ����� ������������"; break;
	case WSAEMSGSIZE: msg = "��������� ������� �������"; break;
	case WSAEPROTOTYPE: msg = "������������ ��� ��������� ��� ������"; break;
	case WSAENOPROTOOPT: msg = "������ � ����� ���������"; break;
	case WSAEPROTONOSUPPORT: msg = "�������� �� ��������������"; break;
	case WSAESOCKTNOSUPPORT: msg = "��� ������ �� ��������������"; break;
	case WSAEOPNOTSUPP: msg = "�������� �� ��������������"; break;
	case WSAEPFNOSUPPORT: msg = "��� ���������� �� ��������������"; break;
	case WSAEAFNOSUPPORT: msg = "��� ������� �� �������������� ����������"; break;
	case WSAEADDRINUSE: msg = "����� ��� ������������"; break;
	case WSAEADDRNOTAVAIL: msg = "����������� ����� �� ����� ���� �����������"; break;
	case WSAENETDOWN: msg = "���� ���������"; break;
	case WSAENETUNREACH: msg = "���� �� ���������"; break;
	case WSAENETRESET: msg = "���� ��������� ����������"; break;
	case WSAECONNABORTED: msg = "����������� ����� �����"; break;
	case WSAECONNRESET: msg = "����� �������������"; break;
	case WSAENOBUFS: msg = "�� ������� ������ ��� �������"; break;
	case WSAEISCONN: msg = "����� ��� ���������"; break;
	case WSAENOTCONN: msg = "����� �� ���������"; break;
	case WSAESHUTDOWN: msg = "������ ��������� send : ����� �������� ������"; break;
	case WSAETIMEDOUT: msg = "���������� ���������� ��������  �������"; break;
	case WSAECONNREFUSED: msg = "���������� ���������"; break;
	case WSAEHOSTDOWN: msg = "���� � ����������������� ���������"; break;
	case WSAEHOSTUNREACH: msg = "��� �������� ��� �����"; break;
	case WSAEPROCLIM: msg = "������� ����� ���������"; break;
	case WSASYSNOTREADY: msg = "���� �� ��������"; break;
	case WSAVERNOTSUPPORTED: msg = "������ ������ ����������"; break;
	case WSANOTINITIALISED: msg = "�� ��������� ������������� WS2_32.DLL"; break;
	case WSAEDISCON: msg = "����������� ����������"; break;
	case WSATYPE_NOT_FOUND: msg = "����� �� ������"; break;
	case WSAHOST_NOT_FOUND: msg = "���� �� ������"; break;
	case WSATRY_AGAIN: msg = "������������������ ���� �� ������"; break;
	case WSANO_RECOVERY: msg = "��������������  ������"; break;
	case WSANO_DATA: msg = "��� ������ ������������ ����"; break;
	case WSA_INVALID_HANDLE: msg = "��������� ���������� �������  � �������"; break;
	case WSA_INVALID_PARAMETER: msg = "���� ��� ����� ���������� � �������"; break;
	case WSA_IO_INCOMPLETE: msg = "������ ����� - ������ �� � ���������� ���������"; break;
	case WSA_IO_PENDING: msg = "�������� ���������� �����"; break;
	case WSA_NOT_ENOUGH_MEMORY: msg = "�� ���������� ������"; break;
	case WSA_OPERATION_ABORTED: msg = "�������� ����������"; break;
	case WSASYSCALLFAILURE: msg = "��������� ���������� ���������� ������"; break;
	default:msg = "����������� ������";
		break;
	}
	return msg;
}

string GetErrorMsg(string place, int code)
{
	return place + " " + GetErrorSocketMsgByCode(code);
}