// 9-NumberQuest.cpp : 기본 프로젝트 파일입니다.

#include "stdafx.h"
#include <iostream>
using namespace std;
using namespace System;

void MyGame();
void RePlay();

int main()
{
	MyGame();
	return 0;
}


void MyGame()
{
	int comNumber, myNumber;

	int score = 10;

	comNumber = rand() % 101;

	while (true)
	{
		cout << "0 ~ 100 사이의 숫자를 입력해 주세요" << endl;
		cin >> myNumber;

		if (myNumber == comNumber)
		{
			cout << "컴퓨터의 입력값과 동일 합니다." << endl;
			break;
		}
		else if (myNumber > comNumber)
		{
			cout << "나의 입력값이 큽니다." << endl;
			score--;
		}
		else
		{
			cout << "나의 입력값이 작습니다." << endl;
			score--;
		}
	}
	//점수 표현
	cout << "점수 : " << score << " 입니다" << endl;
	cout << "한번 더 하시겠습니까 (y,n)" << endl;
	RePlay();
}

//프로그램 재시작
void RePlay()
{
	char select;
	cin >> select;

	if (select == 'y' || select == 'Y')
	{
		cout << "(다음 라운드) 새로운 숫자로 초기화 하였습니다." << endl;
		MyGame();
	}
	else if (select == 'n' || select == 'N')
	{
		cout << "프로그램을 종료합니다.." << endl;
	}
	else
	{
		cout << "잘못입력하셨습니다." << endl;
		RePlay();
	}
}