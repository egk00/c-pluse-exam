#include "stdafx.h"
#include <iostream>
using namespace System;
using namespace std;

class BaseObject
{
private:
	int baseNum;
public:
	BaseObject(int n) : baseNum(n)
	{
		cout << "Base() : " << baseNum << endl;
	}
	~BaseObject()
	{
		cout << "~Base() : " << baseNum << endl;
	}
};

class DerivedObject : public BaseObject
{
private:
	int derivNum;
public:
	DerivedObject(int n) : BaseObject(n), derivNum(n)
	{
		cout << "SoDerived() : " << derivNum << endl;
	}
	~DerivedObject()
	{
		cout << "~SoDerived() :" << derivNum << endl;
	}
};
int main()
{
	DerivedObject drv1(15);
	DerivedObject drv2(30);
    return 0;
}
