#pragma once
// 127.0.0.1�� loop-back IP�� �ؼ�, �ڱ� �ڽſ��� ����Ǵ� IP �ּҸ� ���Ѵ�.
const char serverIP[] = "127.0.0.1";
// Ŭ���̾�Ʈ���� ������ �����ϱ� ���� ��Ʈ
const int IOCP_Port = 12345;

#include <WinSock2.h>
class AutoWSACleanup
{
public:
	~AutoWSACleanup()
	{
		WSACleanup();
	}
};