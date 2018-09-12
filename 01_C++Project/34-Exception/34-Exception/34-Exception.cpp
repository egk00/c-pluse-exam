#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
using namespace System;


int main()
{
	int number;

	try 
	{
		cout << "1~ 10 사이 숫자를 입력해 주세요 : ";
		cin >> number;
		if (number == 0) throw number;
		if (number < 1) throw "낮은 수";
		if (number > 10) throw "높은 수";
	}
	catch (const char *e) 
	{
		cout << "숫자 범위보다 " << e << "를 입력하셨습니다.";
	}
	catch (int e)
	{
		cout << "숫자" << e << "를 입력하셨습니다." << endl;
	}
    return 0;
}
