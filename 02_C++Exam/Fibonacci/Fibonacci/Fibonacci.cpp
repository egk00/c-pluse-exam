#include "stdafx.h"
#include <iostream>
using namespace std;
using namespace System;

int Fibonacci(int n)
{
	if (n <= 2)
		return 1;
	else
		return Fibonacci(n - 2) + Fibonacci(n - 1);
}
int main()
{
	for (int i = 1; i < 10; i++)
	{
		cout << Fibonacci(i) << endl;
	}
    return 0;
}
