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

	bool operator <(const IntClass &ic)
	{
		return this->value < ic.value;
	}
};

class IntClassWrite
{
public:
	void operator ()(IntClass *ic)
	{
		ic->Write();
	}
};

class SortCompare
{
public:
	// sort함수 내부에서 이 두 값을 비교할 함수
	bool operator()(IntClass *a, IntClass *b)
	{
		return *a < *b;
	}
};


int main()
{
	vector<IntClass *> intVector;

	intVector.push_back(new IntClass(6));
	intVector.push_back(new IntClass(9));
	intVector.push_back(new IntClass(7));
	intVector.push_back(new IntClass(2));

	for (vector<IntClass *>::iterator ic = intVector.begin();
		ic != intVector.end(); ++ic)
	{
		(*ic)->Write();
	}

	cout << "세번째에 3 삽입" << endl;
	intVector.insert(intVector.begin() + 2, new IntClass(3));
	for (vector<IntClass *>::iterator ic = intVector.begin();
		ic != intVector.end(); ++ic)
	{
		(*ic)->Write();
	}

	cout << "정렬1" << endl;
	sort(intVector.begin(), intVector.end(), SortCompare());

	for_each(intVector.begin(), intVector.end(), IntClassWrite());
    return 0;
}
