/*
	컴퓨터와 가위바위보 게임
	컴퓨터는 rand()함수로 가위바위보를 정한다.
	사람은 키보드 입력으로 가위바위보를 입력한다.
	결과로 사람이 이겼는지 컴퓨터가 이겼는지 출력한다.
*/
#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace System;
using namespace std;


int main()
{
	enum  RSP { Rock, Scissors, Paper, Erorr };
	// RSP 타입의 변수를 만들면, 거기에는 Rock, Scissors, Paper
	//	라는 값만 넣을 수 있다.
	// 주의 : 여기까지는 앞으로 RSP라는 형태의 변수를 만들겠다는
	//		뜻이며, 아직까지는 변수가 만들어진 것은 아니다.
	RSP comSelect; //컴퓨터의 결정
	comSelect = Rock;
	//c언어의 경우 enum의 구분이 없었다.
	while (true) //들여쓰기 인덴트 indent 텝으로 하면 됨
	{
		// 컴퓨터의 결정
		int comRand = rand() % 3;	// 0, 1, 2

		switch (comRand)
		{
		case 0:
			comSelect = Rock;
			break;
		case 1:
			comSelect = Scissors;
			break;
		case 2:
			comSelect = Paper;
			break;
		default:
			cout << "컴퓨터의 결정에 에러가 생겼습니다." << endl;
			break;
		}
		// 디버그창 안 보일때 디버그 -> 창 -> 자동, 지역



		//////////////////////////////////////////////
		// 사람의 결정
		/////////////////////////////////////////////
		RSP playerSelect; // 사람의 선택
		string playerInput;
		do
		{
			cout << "가위 바위 보를 선택하세요" << endl;
			cout << "	1 : 가위" << endl;
			cout << "	2 : 바위" << endl;
			cout << "	3 : 보" << endl;


			getline(cin, playerInput);

			if (playerInput == "1")
			{
				playerSelect = Scissors;
			}
			else if (playerInput == "2")
			{
				playerSelect = Rock;
			}
			else if (playerInput == "3")
			{
				playerSelect = Paper;
			}
			else
			{
				playerSelect = Erorr;
			}
		} while (playerSelect == Erorr);

		//////////////////////////
		// 출력
		/////////////////////////
		switch (comSelect)
		{
		case Rock:
			cout << "컴퓨터는 바위를 냈습니다." << endl;
			break;
		case Scissors:
			cout << "컴퓨터는 가위를 냈습니다." << endl;
			break;
		case Paper:
			cout << "컴퓨터는 보를 냈습니다." << endl;
			break;
		default:
			break;
		}

		switch (playerSelect)
		{
		case Rock:
			cout << "당신은 바위를 냈습니다." << endl;
			break;
		case Scissors:
			cout << "당신은 가위를 냈습니다." << endl;
			break;
		case Paper:
			cout << "당신은 보를 냈습니다." << endl;
			break;
		default:
			break;

		}

		///////////////////////////////////////
		// 승패 결정
		//////////////////////////////////////
		// 비김 체크 - 양쪽이 같을 경우
		if (comSelect == playerSelect)
		{
			cout << "비겼습니다." << endl;
		}
		else  // 비기지 않은 경우
		{
			if (comSelect == Rock && playerSelect == Scissors)
			{
				cout << "컴퓨터가 이겼습니다." << endl;
			}
			else if (comSelect == Scissors && playerSelect == Paper)
			{
				cout << "컴퓨터가 이겼습니다." << endl;
			}
			else if (comSelect == Paper && playerSelect == Rock)
			{
				cout << "컴퓨터가 이겼습니다." << endl;
			}
			else
			{
				cout << "사람이 이겼습니다." << endl;
			}
		}
	}


	return 0;
}
