// 10-CodeEven.cpp : 기본 프로젝트 파일입니다.

#include "stdafx.h"
#include <iostream>
using namespace std;
using namespace System;

enum Even { Hol, Jax };

int main()
{
	int comScore = 100, myScore = 100;
	cout << "컴퓨터 100점, 나 100점을 가지고 시작 합니다." << endl;

	while (true)
	{

		//컴퓨터의 숫자 정하기( 1~10 )
		int comValue = rand() % 10 + 1;
		Even comEven;
		if (comValue % 2 == 0)
		{
			comEven = Jax;
		}
		else
		{
			comEven = Hol;
		}

		cout << "점수를 배팅해주세요 : ";
		int batScore;
		cin >> batScore;

		//조언 얻기
		cout << "맞을 확률 60%의 조언을 얻으시겠습니까? (받는다 : 0, 받지않는다 : 1) : ";
		int advice;
		cin >> advice;

		if (advice = 0)
		{
			int comValue = rand() % 10 + 1;
			//60% 확인
			if (comValue <= 6)
			{
				if (comValue % 2 == 0)
				{
					cout << "60% 의 확률로 짝입니다." << endl;
				}
				else
				{
					cout << "60% 의 확률로 홀입니다." << endl;
				}
			}
			else
			{
				if (comValue % 2 == 0)
				{
					cout << "60% 의 확률로 홀입니다." << endl;
				}
				else
				{
					cout << "60% 의 확률로 짝입니다." << endl;
				}
			}
		}

		cout << "홀짝을 선택해주세요(짝:0, 홀:1) ";
		int myValue;
		cin >> myValue;
		Even myEven;
		if (myValue == 0)
		{
			myEven = Jax;
		}
		else
		{
			myEven = Hol;
		}

		if (myEven == comEven)
		{
			cout << "컴퓨터의 숫자는 " << comValue << "입니다." << endl;
			cout << "당신이 맞추었습니다." << endl;
			myScore += batScore;
			cout << "현재 당신의 점수" << myScore << endl;
		}
		else
		{
			cout << "컴퓨터의 숫자는 " << comValue << "입니다." << endl;
			cout << "당신이 틀렸습니다." << endl;
			myScore -= batScore;
			cout << "현재 당신의 점수" << myScore << endl;
		}

		if (myScore <= 0)
		{
			cout << "당신은 패배했습니다." << endl;
			break;
		}
	}
	return 0;
}
