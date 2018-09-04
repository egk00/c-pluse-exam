// Operator_Overload2.cpp : 기본 프로젝트 파일입니다.

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
using namespace System;

class MyOut
{
private:
	string myString;
public:
	MyOut()
	{
		myString = "";
	}
	MyOut &operator <<(string myString)
	{
		this->myString += myString;
		return *this;
	}
	void Write()
	{
		cout << myString << endl;;
	}
};
int main()
{
	MyOut myout;
	myout << "Hello " << "World!";
	myout.Write();
	return 0;
}