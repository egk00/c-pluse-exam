#include "pch.h"
#include <iostream>
using namespace std;
#include <WinSock2.h>
#pragma comment(lib, "Ws2_32.lib")
#include "../IOCP-Start.h"
#include <process.h>

const int maxWorkingThread = 4;		// 4개의 워킹스레드가 돌아간다.
unsigned int __stdcall IOCPWorkingThread(void *arg);	// working thread
int main()
{
	// winsock 초기화
	WSADATA WSAData;
	if (WSAStartup(MAKEWORD(2, 2), &WSAData) != 0)
	{
		cout << "winsock 초기화 오류" << endl;
	}
	AutoWSACleanup autoWSACleanup;

	// 소켓 생성
	SOCKET listenSocket = 
		WSASocket(AF_INET, SOCK_STREAM, 0, nullptr, 0, WSA_FLAG_OVERLAPPED);
	// 소켓 생성 실패면 INVALID_SOCKET을 반환
	if (listenSocket == INVALID_SOCKET)
	{
		cout << "소켓 생성에 실패했습니다." << endl;
		return 1;
	}
	SOCKADDR_IN socketInfo;
	memset(&socketInfo, 0, sizeof(socketInfo));
	socketInfo.sin_family = PF_INET; // 4바이트 주소 체계
	socketInfo.sin_port = htons(IOCP_Port); // 서버로 접속할 포트
	socketInfo.sin_addr.S_un.S_addr = htonl(INADDR_ANY);

	if (bind(listenSocket,
		(SOCKADDR *)&socketInfo, sizeof(socketInfo)) == SOCKET_ERROR)
	{
		cout << "소켓 바인드 에러" << endl;
		return 1;
	}

	if (listen(listenSocket, 5) == SOCKET_ERROR)
	{
		cout << "리슨 함수 실행 실패" << endl;
		return 1;
	}

	// IOCP 객체 만들기
	HANDLE iocpHandle = CreateIoCompletionPort(
		INVALID_HANDLE_VALUE,
		nullptr,
		0,
		maxWorkingThread);

	if (iocpHandle == INVALID_HANDLE_VALUE)
	{
		cout << "IOCP 객체 실패" << endl;
		return 1;
	}

	// IOCP용 워킹 스레드
	for (int cnt = 0; cnt < maxWorkingThread; ++cnt)
	{
		_beginthreadex(
			nullptr,
			0,
			IOCPWorkingThread,
			&iocpHandle,
			0,
			nullptr);
	}

	while (true)
	{
		SOCKADDR_IN clientInfo;
		int size = sizeof(clientInfo);
		SOCKET socktoClient = accept(listenSocket, (SOCKADDR *)&clientInfo, &size);

		if (socktoClient == INVALID_SOCKET)
		{
			cout << "잘못된 소켓입니다." << endl;
			continue;
		}
		cout << "클라이언트로부터의 접속 확인!!" << endl;
	}
}

unsigned int __stdcall IOCPWorkingThread(void *arg)
{
	HANDLE *hndPnt = (HANDLE *)arg;
	HANDLE iocpHandle = *hndPnt;

	while (true)
	{
		//more coding
	}
	return 0;
}
