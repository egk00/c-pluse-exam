//Mize.cpp
#include "stdafx.h"
#include "Mize.h"

Mize::Mize() // �̷� ������
{	// �̷� ��ü�� ��ֹ��� �ϳ��� ������ ����
	for (int y = 0; y < mizeSize; ++y)
	{
		for (int x = 0; x < mizeSize; ++x)
		{
			cell[y][x] = EmptyCell;
		}
	}

	// �߰��� ��ֹ��� ����
	for (int x = 3; x < mizeSize - 2; ++x)
		cell[x][mizeSize / 2] = Obstacle;
	for (int y = 3; y < mizeSize - 2; ++y)
		cell[mizeSize / 2][y] = Obstacle;
}

Coord::Coord(int x, int y)	// ��ǥ x, y���� ������
{
	this->x = x;
	this->y = y;
}

Monster::Monster(int x, int y)	// ���� ��ġ ���� ������
	: locate(x, y)
{

}

UnitMove::UnitMove(Coord locate, Coord from, float distFromStart)
	: locate(locate), from(from)
{
	this->distFromStart = distFromStart;

}

void Monster::PathFind(Mize &mize, int goalX, int goalY)	// ��ǥ ��ġ ����
{
	PathFind(mize, locate, Coord(goalX, goalY));	// ���� ��ġ -> ��ǥ ��ġ Ž��
}

void Monster::PathFind(Mize &mize,Coord from, Coord goal) // ���� ��ġ -> ��ǥ ��ġ Ž��
{
	UnitMoveList openList;	// ������ �� �� �ִ� ����
	UnitMoveList closeList;	// �̹� �̵��� ����

	// 1. ������ ���� ��ġ ������ �� �� �ִ� �������� ����
	openList.push_back(UnitMove(from, from, 0));

	while (true)
	{
		if (openList.empty())	// ����Ʈ�� ��� �ִٸ�
		{
			cout << "���� ã�� �� ����" << endl;
			return;
		}

		UnitMove cell = openList.ShortestPath();

		if (cell.locate.x == goal.x && cell.locate.y == goal.y)
		{	// goal ������ ��ü ��ã�� ����!!
			// closeList���� ��ü ��� ã��
			closeList.TotalPath(cell);
			return;
		}

		for (int dy = -1; dy <= 1; ++dy)
		{
			for (int dx = -1; dx <= 1; ++dx)
			{
				// dy�� dx�� 0�� �ƴ� ��ġ
				if (dy != 0 || dy != 0)
				{
					// ���� ��ġ(x,y) x + dx , y + dy 
					Coord nextCell(cell.locate.x + dx, cell.locate.y + dy);

					if (!mize.CanEntry(nextCell))
					{
						continue;
					}

					if (closeList.IsInList(nextCell))
					{	// closeList �ȿ� nextCell�� ��� �ִ�.
						// => nextCell ��ġ�� �̹� �˻��� ������!
						continue;
					}

					// ���� nextCell�� openList �ȿ� �ִٸ� 
					// �̹� ������ ���� ��ü�̹Ƿ� �ٽ� ���������� �ʿ䰡 ����.
					if (openList.IsInList(nextCell))
					{	// openList �ȿ� nextCell�� ��� �ִ�.
						continue;
					}

					// ���� ���� ������ nextCell �� ������ ������ Ž���� �ؾ��Ѵ�.
					// openList�� �߰� �ؼ� ������ nextCell�� �߽�����
					// Ž���� �ؾ� �Ѵ�.
					float dist_Cell_NextCell;
					if (dx == 0 || dy == 0)		// �¿� �Ǵ� ���� ������ ���
						dist_Cell_NextCell = 1;
					else   // �밢�� ����
						dist_Cell_NextCell = 1.414;


					float distance = cell.distFromStart + dist_Cell_NextCell;
					openList.push_back(UnitMove(nextCell, cell.locate, distance));
				}
			}
		}

		// ���� �����ؼ� openList���� ���� cell�� �������⼿ Ž�� �Ϸ�
		closeList.push_back(cell);
	}
}

bool::Mize::CanEntry(Coord coords)
{
	// (x, y)�� �� �� �ִ��Ĵ� �� ��ġ�� ���� ����ִ��Ĵ� ��
	int x = coords.x;
	int y = coords.y;

	// �̷� ���� ������ ���� ���� ����.
	if (x < 0 || x >= mizeSize)
		return false;
	if (y < 0 || y >= mizeSize)
		return false;

	if (cell[x][y] == EmptyCell)
		return true;
	return false;
}