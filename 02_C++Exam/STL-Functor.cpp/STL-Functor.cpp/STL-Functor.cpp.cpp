// STL-Functor.cpp : 기본 프로젝트 파일입니다.

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm> // for each 사용하기 위해 선언
using namespace std;
using namespace System;

class IntClass
{
private:
	int value;
public:
	IntClass(int value)
	{
		this->value = value;
	}
	void Write()
	{
		cout << value << endl;
	}
};
// 함수 객체 생성 연산자()를 오버로드함
class IntClassWrite
{
public:
	void operator()(IntClass *ic)
	{
		ic->Write();
	}
};

int main()
{
	vector<IntClass *> intVector;

	intVector.push_back(new IntClass(6));
	intVector.push_back(new IntClass(8));
	intVector.push_back(new IntClass(3));
	intVector.push_back(new IntClass(5));
	intVector.push_back(new IntClass(9));

	for_each(intVector.begin(), intVector.end(), IntClassWrite());
	return 0;
}