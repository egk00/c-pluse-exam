#include "stdafx.h"
#include <iostream>
using namespace std;
using namespace System;

template <typename T>
class Point
{
private:
	T xpos, ypos;
public:
	Point(T x=0, T y=0) : xpos(x), ypos(y){}
	void ShowPosistion() const
	{
		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}
};
int main()
{
	Point<int> pos1(3, 4);
	pos1.ShowPosistion();

	Point<double> pos2(2.4, 3.6);
	pos2.ShowPosistion();

	Point<char> pos3('P', 'F');
	pos3.ShowPosistion();
    return 0;
}
