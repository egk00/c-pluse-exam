// Client.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include "../IOCP-Start.h"
#include <iostream>
#include <WinSock2.h>
#pragma comment(lib, "Ws2_32.lib")

using namespace std;

int main()
{
	// 소켓 초기화
	WSADATA WSAData;
	if (WSAStartup(MAKEWORD(2, 2), &WSAData) != 0)
	{
		cout << "winSock 초기화 실패" << endl;
		return 1;
	}

	AutoWSACleanup autoWSACleanup;

	// 소켓 생성
	SOCKET toServer;
	toServer = WSASocket(
	AF_INET, SOCK_STREAM, 0, nullptr, 0, WSA_FLAG_OVERLAPPED);

	if (toServer == INVALID_SOCKET)
	{
		cout << "소켓 만들기 실패" << endl;
		return 1;
	}

	SOCKADDR_IN serverAddr;
	memset(&serverAddr, 0, sizeof(serverAddr));
	serverAddr.sin_family = PF_INET;
	serverAddr.sin_addr.S_un.S_addr = inet_addr(serverIP); // 서버 IP
	serverAddr.sin_port = htons(IOCP_Port);

	int connectResult = connect(toServer, (SOCKADDR *)&serverAddr, sizeof(serverAddr));

	if (connectResult == SOCKET_ERROR)
	{
		cout << "접속 실패" << endl;
		return 1;
	}
	cout << "접속 성공" << endl;
	return 0;
}