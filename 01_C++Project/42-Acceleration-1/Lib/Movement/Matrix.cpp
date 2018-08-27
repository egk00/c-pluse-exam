#include "stdafx.h"
#include "Matrix.h"
#include <math.h>

Matrix31::Matrix31()
{
	matrix[0] = matrix[1] = 0;
	matrix[2] = 1;
}

Matrix31::Matrix31(float x, float y)
{
	matrix[0] = x;
	matrix[1] = y;
	matrix[2] = 1;
}

Matrix33::Matrix33()
{
	for (int y = 0; y < 3; ++y)
	{
		for (int x = 0; x < 3; ++x)
		{
			// matrix ��� 0���� ä���
			matrix[y][x] = 0;
			// �밢�� 1�� ä���
			if (y == x)
			{
				matrix[y][x] = 1;
			}
		}
	}
}

float Matrix31::GetX()
{
	return matrix[0];
}

float Matrix31::GetY()
{
	return matrix[1];
}

// �����̵� ��Ʈ����
void Matrix33::ParallelMoveMent(float dx, float dy)
{
	matrix[2][0] = dx;
	matrix[2][1] = dy;
}

void Matrix33::RotationMovement(float degree)	// ȸ���� ��Ʈ������ ����(�μ��� degree)
{
	// �츮�� ���� ���� degree(360��) ��������, ���̺귯�� �ﰢ�Լ�����
	// �޴� ���� ����(2pi)���̴�.
	// �׷��Ƿ� ���⼭ degree�� radian���� �ٲپ� �Է��ؾ� �Ѵ�.
	// �׷��� ���ؼ��� degree�� pi / 180���� ���ؾ� �Ѵ�.
	float Cos = cos(degree * pi / 180);
	float Sin = sin(degree * pi / 180);
	matrix[0][0] = Cos;
	matrix[1][0] = -Sin;
	matrix[0][1] = Sin;
	matrix[1][1] = Cos;
}

void Matrix33::ParallelMovement(float dx, float dy)
{
	// 2���� �迭 ÷�ڸ� ����� �� ���� matrix[row][colum]��
	// ���������, ÷���� ��Ģ�� Ȯ���ϰ� ���Ѵٸ� �ٸ�
	// ������ ÷��ü�踦 ����� �� �ִ�.
	// ���⼭�� ����� X, Y��ǥ�� ���� �迭�� matrix[x][y]��
	// ���Ѵ�.

	matrix[2][0] = dx;
	matrix[2][1] = dy;
}

Matrix31 Matrix33::operator *(Matrix31 &matrix31)
{
	Matrix31 result;

	for (int resultSlot = 0; resultSlot < 3; ++resultSlot)
	{
		for (int idx = 0; idx < 3; ++idx)
		{
			result.matrix[resultSlot] += this->matrix[idx][resultSlot] * matrix31.matrix[idx];
		}
	}
	return result;
}

Matrix33 Matrix33::operator *(Matrix33 &matrix33)
{
	Matrix33 result;
	for (int resultX = 0; resultX < 3; ++resultX)
	{
		for (int resultY = 0; resultY < 3; ++resultY)
		{
			result.matrix[resultX][resultY] = 0;
			for (int index = 0; index < 3; ++index)
			{
				result.matrix[resultX][resultY] +=
					this->matrix[index][resultY] *
					matrix33.matrix[resultX][index];
			}
		}
	}
	return result;
}