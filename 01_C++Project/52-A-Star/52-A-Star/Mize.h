#pragma once
#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

const int mizeSize = 10;	// �̷� ������
// ������ ����ְų� ��ֹ��� �ִ�.
enum CellType { EmptyCell, Obstacle};
class Coord;
class Mize	// �̷θ� ������ ��ü
{
private:
	CellType cell[mizeSize][mizeSize];

public:
	Mize();
	bool CanEntry(Coord coords);	// ��ǥ �ȿ� �� �� �ִ°�?

	void Print()
	{
		for (int y = 0; y < mizeSize; ++y)
		{
			for (int x = 0; x < mizeSize; ++x)
			{
				cout << (cell[x][y] == EmptyCell ? " ." : " #");
			}
			cout << endl;
		}
	}
};

class Coord	// �̷� �� ��ġ�� ��Ÿ���� ��ǥ
{
public:
	int x, y;
	Coord(int x, int y);
};

class UnitMove	// �̷� �ȿ� ��ĭ �̵��ϴ� ����� ��ü
{
public:
	Coord locate;	// ���� ��ġ
	Coord from;		// �̵� ����
	float distFromStart;	// ��ã�� ������ ��ġ�κ����� �Ÿ�
	UnitMove(Coord from, Coord goal, float distFromStart);
};

class Monster
{
private:
	Coord locate;	// ���� ��ġ
	void PathFind(Mize &mize, Coord from, Coord goal);	// ��ã�� �Լ�
	// ���� ��ġ ����, ������ ��ġ
public:
	Monster(int x, int y);	//������
	void PathFind(Mize &mize, int goalX, int goalY);	// ������ ���� �Լ�
};

// ��ã�� �� ���¸���Ʈ�� Ŭ���� ����Ʈ�� ��� �����ϱ� ���� ��ü
class UnitMoveList : public list<UnitMove>
{
public:
	// �� ����Ʈ �ȿ� nextCell�� �ִ��� Ȯ���ϱ� ���� �޼���
	bool IsInList(Coord &nextCell)
	{
		// this�� ����Ʈ �ȿ��� nextCell�� ��ġ�ϴ� unitMove�� �ִ��� Ȯ���Ѵ�.

		iterator fnd = find_if(begin(), end(),
			[&nextCell](UnitMove &unitMove)->bool
		{
			if (unitMove.locate.x == nextCell.x &&
				unitMove.locate.y == nextCell.y)
				return true;
			return false;
		});
		if (fnd == end())	// �� ã�Ҵ�!!
			return false;
		return true;
	}

	void TotalPath(UnitMove goal)
	{
		list<Coord> path;
		while (true)
		{
			path.push_front(goal.locate);

			// ���� �������� from�� locate�� ���� �־����Ƿ�, �� ���� ���ٴ� ����
			// ���� ��ġ ���� �����ߴٴ� ��
			if (goal.from.x == goal.locate.x && goal.from.y == goal.locate.y)
			{
				// �н� ���
				for (list<Coord>::iterator crd = path.begin(); crd != path.end(); ++crd)
				{
					cout << crd->x << "," << crd->y << endl;
				}
				return;
			}
			// goal�� goal.from���� �����Ƿ� ����Ʈ���� goal.from�� ã�ƾ� �Ѵ�.
			iterator fnd = find_if(begin(), end(),
				[&goal](UnitMove &unitMove)->bool
			{
				if (unitMove.locate.x == goal.from.x &&
					unitMove.locate.y == goal.from.y)
					return true;
				return false;
			});

			if (fnd == end())
			{
				cout << "���� �߰����� �����.!!";
				return;
			}
			goal = *fnd;	//goal�� ��ġ�� fnd�� �ٲ�
		}
	}

	UnitMove ShortestPath()
	{
		// 1. ù ��° ��ü�� ���� ª�� ��ζ� �����Ѵ�.
		iterator shotest = begin();

		// 2. �ٸ� ��ü��� ���ؼ� �� ª�� ���� ������ �װ��� ���� ª�� ������ ����
		for (iterator cell = begin();
			// vector�� �ƴ϶� list�̹Ƿ�
			// cell = begin() + 1; �� ��� �Ұ�
			cell != end(); ++cell)
		{
			if (shotest->distFromStart > cell->distFromStart)
				shotest = cell;
		}

		// 3. ������� ���� shortest���� ���� ª�� ��ΰ� ������ �ȴ�.
		UnitMove rtnValue = *shotest;
		erase(shotest);
		return rtnValue;
	}
};
