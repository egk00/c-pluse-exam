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
	IntClass(int value)
	{
		this->value = value;
	}
	void Write()
	{
		cout << value << endl;
	}
};

int main()
{
	vector<IntClass> intVector;

	intVector.push_back(IntClass(5));
	intVector.push_back(IntClass(8));

	for (vector<IntClass>::iterator index = intVector.begin();
		index != intVector.end();
		++index)
	{
		index->Write();
	}

	cout << endl;
	cout << "중간에 끼워넣기" << endl;
	/*
		insert(반복자, 객체);	// 반복자 위치에 객체 추가
	*/
	intVector.insert(intVector.begin() + 1, IntClass(10));
	for (vector<IntClass>::iterator index = intVector.begin();
		index != intVector.end();
		++index)
	{
		index->Write();
	}
	cout << endl;

	cout << "중간에서 제거하기" << endl;
	/*
		erase(반복자);	// 반복자 위치의 객체 제거
	*/
	intVector.erase(intVector.begin());
	for (vector<IntClass>::iterator index = intVector.begin();
		index != intVector.end();
		++index)
	{
		index->Write();
	}
    return 0;
}
