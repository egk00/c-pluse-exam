#include "stdafx.h"
#include "Vector.h"


Vector::Vector(float degree, float length)
{
	this->degree = degree;
	this->length = length;
}

void Vector::DeltaXY(float &dx, float &dy)
{
	dx = sin(degree * pi / 180) * length;
	dy = -cos(degree * pi / 180) * length;
}

Vector &Vector::operator +=(Vector &vector)
{	// this�� vector�� +������ �ؼ�, �� �����
	// this�� �����ϴ� �޼���
	// �� ������ ���� �� ������ x, y ������ ���� ����
	// ���Ϳ� �����Ƿ�
	float myDX, myDY;
	this->DeltaXY(myDX, myDY); // this�� �и� x, y�� �и�

	float vectorDX, vectorDY;
	vector.DeltaXY(vectorDX, vectorDY);	// vector�� x, y�� �и�

	// ������͸� x, y�� ���� ��
	float resultDX = myDX + vectorDX;
	float resultDY = myDY + vectorDY;

	degree = atan2(resultDY, resultDX) * 180 / pi + 90;
	length = sqrt(resultDX * resultDX + resultDY * resultDY);
	// ������ ��Ҹ� ���ϱ� ���ؼ��� sqrt�� ������ �ʰ�
	// ������ �������¿��� ���� �� ������,
	// ���⼭�� length�� ��Ȯ�ϰ� ���̰��� ������ �ֱ� ������
	// sqrt�� ���� ����ؾ� �Ѵ�.
	// ���� degree�� length�� ��� this�� ������̹Ƿ�
	// +=�����ڴ�� �ڽ��� ���� ���ŵǾ���.
	// ���������� this ��ü�� ��ȯ�ϸ� ��
	return *this;
}