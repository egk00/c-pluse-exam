// 3-Myinfo.cpp : 기본 프로젝트 파일입니다.

// 내 이름, 나이, 키, 주소, .... 등을 입력받아 출력하는 프로그램을 작성하라.
#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;
using namespace System;


int main()
{
	string name;
	int age, height;
	string address;

	cout << "이름을 입력해주세요 : ";
	cin >> name;
	cout << "나이를 입력해주세요 : ";
	cin >> age;
	cout << "키를 입력해주세요 : ";
	cin >> height;
	//키와 몸무게 동시 받기 cin >> age >> height;
	cout << "주소를 입력해주세요 : ";
	cin.ignore(); // 입력에 남아있는 데이터 제거
	getline(cin, address);// 라인 전체를 받아 주소에 넣는다.

	cout << "이름 : " << name << ", 나이 : " << age << ", height : " << height << ", 주소 : " << address << endl;
	return 0;
}
