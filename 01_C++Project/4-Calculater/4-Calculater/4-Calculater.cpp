//두 수를 읽어들여 사칙연산을 출력하는 프프로그램을 작성하여라
#include "stdafx.h"
#include<iostream>
using namespace std;
using namespace System;

int main()
{
	int inputValueA, inputValueB;

	int switchValue;

	cout << "두 수를 입력하세요 : ";

	cin >> inputValueA >> inputValueB;

	cout << "(1) 더하기 (2) 빼기 (3) 곱하기 (4) 나누기 (5) 나머지 , 이외 입력 종료" << endl;
	cout << "선택 하세요 : ";
	cin >> switchValue;
	switch (switchValue)
	{
	case 1:
		cout << inputValueA + inputValueB << endl;
		break;
	case 2:
		cout << inputValueA - inputValueB << endl;
		break;
	case 3:
		cout << inputValueA * inputValueB << endl;
		break;
	case 4:
		cout << inputValueA / inputValueB << endl;
		break;
	case 5:
		cout << inputValueA % inputValueB << endl;
		break;

	default:
		return 0;
		break;
	}
	return 0;
}