// 2-inputOutput.cpp : 기본 프로젝트 파일입니다.

#include "stdafx.h"
#include<iostream>
#include<string>
#include<stdio.h>
using namespace System;
using namespace std;

void MyFunc()
{
	cout << "나의 나이는 10살 입니다." << endl;
}

void MyFunc(int a)
{
	cout << "나의 나이는 " << a << "살 입니다." << endl;
}


int main()
{
	MyFunc();
	MyFunc(30);
	return 0;
}
