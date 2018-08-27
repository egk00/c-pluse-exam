#include "stdafx.h"
#include "Vector.h"
#include <math.h>

Vector::Vector(float degree, float length)
{
	this->degree = degree;
	this->length = length;
}

void Vector::DeltaXY(float &dx, float &dy)
{	// ���͸� x��� y������ ������ �Լ�
	dx = sin(degree * pi / 180) * length;
	dy = -cos(degree * pi / 180) * length;
}

Vector &Vector::operator +=(Vector &vector)
{	// this�� vector�� +������ �ؼ�, �� ����� this�� �����ϴ� �޼���

	float thisDX, thisDY;			// this�� dx�� dy�� ������ ����
	this->DeltaXY(thisDX, thisDY);	// this�� �и� x, y�� �и�

	float vectorDX, vectorDY;
	vector.DeltaXY(vectorDX, vectorDY);	// vector�� x, y�� �и�

	float resultDX = thisDX + vectorDX;	// x���� ���� ����
	float resultDY = thisDY + vectorDY;	// y���� ���� ����

	degree = atan2(resultDY, resultDX) * 180 / pi + 90;
	length = sqrt(resultDX * resultDX + resultDY * resultDY);

	return *this;
}

