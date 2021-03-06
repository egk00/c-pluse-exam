#include "stdafx.h"
#include <iostream>
#include <algorithm>
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
	bool operator <(const IntClass &ic)
	{
		return this->value < ic.value;
	}
};
int main()
{
	vector<IntClass *> intClass;

	intClass.push_back(new IntClass(6));
	intClass.push_back(new IntClass(3));
	intClass.push_back(new IntClass(8));
	intClass.push_back(new IntClass(5));
	intClass.push_back(new IntClass(9));

	// 전체 출력
	for (vector<IntClass *>::iterator ic = intClass.begin();
		ic != intClass.end(); ++ic)
	{
		(*ic)->Write();
	}

	sort(intClass.begin(), intClass.end(),
		[](IntClass *a, IntClass *b)->bool
	{
		return *a < *b;
	});

	// 전체 출력
	cout << "정렬 후 출력" << endl;
	for (vector<IntClass *>::iterator ic = intClass.begin();
		ic != intClass.end(); ++ic)
	{
		(*ic)->Write();
	}
	return 0;
}