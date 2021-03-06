// vector1.cpp : 기본 프로젝트 파일입니다.

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
using namespace System;

class IntClass
{
private:
	int value;
public:
	IntClass()	// 기본 생성자
	{
		this->value = 0;
		cout << "IntClass::IntClass() 생성자" << endl;
	}
	IntClass(int value)	// 인자 입력 시 호출 생성자
	{
		this->value = value;
		cout << "IntClass:IntClass(int value) 인자 입력 시 호출 생성자" << endl;
	}
	IntClass(const IntClass &ic)	// 복사 생성자
	{
		this->value = ic.value;
		cout << "IntClass::IntClass(const IntClass &ic) 복사 생성자" << endl;
	}
	~IntClass()	// 소멸자
	{
		cout << "IntClass:~IntClass() 소멸자" << endl;
	}
	void operator = (const IntClass &ic)
	{
		this->value = ic.value;
		cout << "void IntClass::operaor =(const IntClass &ic)" << endl;
	}
};

int main()
{
	vector<IntClass> intClassVector;

	intClassVector.push_back(IntClass(10));
	intClassVector.push_back(IntClass(6));
	Console::WriteLine("push_back 종료");
	return 0;
}