#include "stdafx.h"
#include<iostream>
#include<random>
using namespace std;
using namespace System;

int main()
{
	cout << "6개 랜덤 수 출력" << endl;
	cout << rand() << endl;
	cout << rand() << endl;
	cout << rand() << endl;
	cout << rand() << endl;
	cout << rand() << endl;
	cout << rand() << endl;

	cout << "0~7 가지 랜덤 수 출력" << endl;
	cout << rand() % 7 << endl;

	cout << "주사위 게임을 위한 난수" << endl;

	// RAND_MAX : rand()함수가 만들 수 있는 난수의 최고값
	// rand()함수로 만들 수 있는 난수 범위 : 0~RAND_MAX
	//(float)rand() / RAND_MAX + 1) : 항상 0~1사이의 값이 나온다.(1이 될 수는 없음)
	//(float)rand() / RAND_MAX + 1) * 6 : 항상 0~5 사이
	//(float)rand() / RAND_MAX + 1) * 6 + 1 : 항상 1~6 사이
	//(int)((float)rand() / RAND_MAX + 1) * 6 + 1) : 1~6 사이의 정수
	cout << (int)((float)rand() / (RAND_MAX + 1) * 6 + 1) << endl;
	cout << (int)((float)rand() / (RAND_MAX + 1) * 6 + 1) << endl;
	cout << (int)((float)rand() / (RAND_MAX + 1) * 6 + 1) << endl;
	cout << (int)((float)rand() / (RAND_MAX + 1) * 6 + 1) << endl;

	return 0;
}
