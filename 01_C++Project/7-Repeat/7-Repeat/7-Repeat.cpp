#include "stdafx.h"
#include <iostream>
using namespace std;
using namespace System;

int main()
{
	int loopVar = 0; //반복 변수
	while (loopVar < 10)
	{
		cout << "While from 0, loopVar = " << loopVar << endl;
		loopVar++;
	}
	loopVar = 0;
	do
	{
		cout << "Do-While from 0, loopVar = " << loopVar << endl;
		loopVar++;
	} while (loopVar < 10);



	loopVar = 10;
	while (loopVar < 10)
	{
		cout << "While from 10, loopVar = " << loopVar << endl;
		loopVar++;
	}
	loopVar = 10;
	do
	{
		cout << "Do-While from 10, loopVar = " << loopVar << endl;
		loopVar++;
	} while (loopVar < 10);

	int sum = 0;
	for (int i = 1; i <= 100; i++)
	{
		sum += i;
	}
	cout << "결과 : " << sum << endl;
	return 0;
}
