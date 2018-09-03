#pragma once
#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

const int mizeSize = 10;	// �̷� ������
// ������ ����ְų� ��ֹ��� �ִ�.
enum CellType { EmptyCell, obstacle};
class Coord;
class Mize	// �̷θ� ������ ��ü
{
private:
	CellType cell[mizeSize][mizeSize];

public:
	Mize();
	bool CanEntry(Coord coords);	// ��ǥ �ȿ� �� �� �ִ°�?
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
	UnitMove(Coord from, Coord goal);
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