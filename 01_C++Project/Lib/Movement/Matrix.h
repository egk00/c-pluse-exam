#pragma once

const float pi = 3.14159;
class Matrix33;

class Matrix31
{
private:
	float matrix[3];

public:
	Matrix31();
	Matrix31(float x, float y);
	float GetX();
	float GetY();

	friend Matrix33;
};

class Matrix33
{
private:
	float matrix[3][3];

public:
	Matrix33();
	void ParallelMoveMent(float dx, float dy);		// ����� �����̵� ���
	void RotationMovement(float degree);			// ȸ���� ��Ʈ������ ����(�μ��� degree)
	void ParallelMovement(float dx, float dy);

	Matrix31 operator *(Matrix31 &matrix31);
	Matrix33 operator *(Matrix33 &matrix33);
};