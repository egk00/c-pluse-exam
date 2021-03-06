// Operator_Overload1.cpp : 기본 프로젝트 파일입니다.

#include "stdafx.h"
#include <iostream>
using namespace std;
using namespace System;

class Point
{
private:
	int locX;
	int locY;
public:
	Point(int x, int y) : locX(x), locY(y) {}	// 멤버이니셜라이즈를 통해 초기화
	void Print()	//  x와 y 출력
	{
		cout << "( " << locX << " , " << locY << " )" << endl;
	}
	Point operator+(const Point &other)
	{
		Point returnPoint(0, 0);
		returnPoint.locX = this->locX + other.locX;
		returnPoint.locY = this->locY + other.locY;
		return returnPoint;
	}
};
int main()
{
	Point p1(2, 3);
	cout << "p1 : ";
	p1.Print();
	Point p2(4, -2);
	cout << "p2 : ";
	p2.Print();
	Point result = p1 + p2;
	cout << "p1 + p2 : ";
	result.Print();
	return 0;
}