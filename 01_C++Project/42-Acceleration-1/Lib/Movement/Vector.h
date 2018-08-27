#pragma once
#include "Matrix.h"

class Vector
{
private:
	float degree;		// ������ ����
	float length;		// ������ ��Į��

public:
	Vector(float degree, float length);
	void DeltaXY(float &dx, float &dy);	// ���͸� x��� y������ ������ �Լ�
	float GetDegree()
	{
		return degree;
	}
	Vector &operator +=(Vector &vector);
};
