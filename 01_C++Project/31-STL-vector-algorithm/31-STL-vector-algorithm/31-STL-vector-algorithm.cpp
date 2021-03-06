#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
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
	/*
	벡터에서 특정객체를 찾기 위해서는 두 객체간의 같은지 다른지 판단하는 것이
		필요하므로 비교연산자(==)를 오버로드해야 한다.
	*/
	bool operator==(const IntClass &ic)
	{
		return this->value == ic.value;
	}
	/*
	정렬을 하기 위해서는 두 객체간의 대소비교가 필요하므로
	객체간의 대소비교를 위한 연산자(<)를 오버로드해야 한다.
	*/
	bool operator <(const IntClass &ic)
	{
		return this->value < ic.value;
	}
};

int main()
{
	vector<IntClass> intVector;
	intVector.push_back(IntClass(10));
	intVector.push_back(IntClass(5));
	intVector.push_back(IntClass(8));
	intVector.push_back(IntClass(6));
	for (vector<IntClass>::iterator index = intVector.begin();
		index != intVector.end();
		++index)
	{
		index->Write();
	}
	cout << endl;

	cout << "1. find : 객체 찾기" << endl;
	vector<IntClass>::iterator fnd = 
		find(intVector.begin(),intVector.end(),IntClass(8));

	if (fnd != intVector.end())
		fnd->Write();
	else
		cout << "찾지 못했습니다." << endl;
	cout << endl;

	cout << "2. sort : 자료 정렬" << endl;
	sort(intVector.begin(), intVector.end());
	for (vector<IntClass>::iterator index = intVector.begin();
		index != intVector.end();
		++index)
	{
		index->Write();
	}
    return 0;
}
