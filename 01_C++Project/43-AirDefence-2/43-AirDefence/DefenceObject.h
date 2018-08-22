#pragma once
#include "../../Lib/Movement/Vector.h"
#include "../../Lib/Movement/Matrix.h"
#include <list>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")	// timeGetTime() �Լ��� ���ԵǾ� �ִ� ���̺귯��
#include <stdlib.h>					// rand()�� ����ϱ� ���� ���

// ���ӿ� ������ ��� ����
const float fieldWidth = 1000;					// ȭ�� ����
const float fieldHeight = 800;					// ȭ�� ����

const float gravityAccelerate = 9.8;		// �߷� ���ӵ�

const float airplainSpeedPerSec = 30;			// ����� �ʼ�
const float airplainSize = 20;					// ����� ũ��

// Ÿ�̸� ����
const int Timer_AirplainRegen_ID = 1;			// ����� ���� ID
const int Timer_AirplainRegen_Interval = 1000;	// 1�� �������� ����

const int Timer_ObjectRoutine_ID = 2;			// �̹��� �� ������Ʈ���� �ؾ��� ��
const int Timer_ObjectRoutine_Interval = 50;

const float bombSize = 10;
const int bombDropRate = 1;	// ����⿡�� ��ź ������ Ȯ��

class Behavior;
class ObjList;

class BaseObject
{
protected:
	float locX;			// ȭ�� ���� ������ ������ ��ġ
	float height;		// ������Ʈ�� �� - ȭ�� �Ʒ��ʺ����� ��ġ
	Vector velocity;		// �ӵ�
	long lastMoveTime;	// ���������� �̵��� �ð�
	Behavior *behavior;	// �� ������Ʈ�� �������� �����Ѵ�.
	BaseObject(float locX, float height, float degree, float speed);
	

	// ������Ʈ���� �׸��� ���� ��ǥ�� ��ȯ�� ��Ʈ������ ����� �޼���
	Matrix33 TranslateMatrix();

public:
	virtual void Draw(HDC hdc) = 0;
	virtual ~BaseObject();
	// 1. �Ҹ��ڴ� ��� ȣ����� �𸣹Ƿ� �׻�
	//		public�� �Ǿ�� �Ѵ�.
	// 2. BaseObject���� ��ӵ� Ŭ������ �Ҹ��ڵ�
	//		���� �����ϱ� ���ؼ��� �����Լ��� ������ �Ѵ�.

	void Routine(ObjList & objList);	//�ൿ
	virtual void OtherRoutine(ObjList & objList);
};


class Airplain : public BaseObject
{
private:
	static Matrix31 lines[3][2];		// �� ������ �Ϸ�
	static bool initializeComplate;

public:
	Airplain(float height);
	void Draw(HDC hdc) override;
	void OtherRoutine(ObjList & objList) override;
};

// ���ӿ� ������ ��� ������Ʈ���� �������� �����ϴ� Ŭ����
// ���� ������� �������̶��, 
// behavior���� ��� ���� UniformMoveing�� �����Ѵ�.
class Behavior
{
public:
	virtual void Move(Vector &velocity, float interval, float &locX, float &height) = 0;
	// velocity�� ��ü�̸� 
	// ��Ȳ�� ���� ���� �ٲ� �� �����Ƿ�
	// loCX, height�� ��������Ʒ �ٲ� ���� �޾ƾ� �ϹǷ�
	// ������ �ʿ�
};
class UniformMoving : public Behavior
{
	// ������Ʈ�� ��ӿ�ϰ� ����� ��ü
public:
	void Move(Vector &velocity, float interval, float &locX, float &height) override;
};

// ��ź
class Bomb : public BaseObject
{
private:
	static Matrix31 lines[4][2];
	static bool initializeComplete;
public:
	Bomb(float locX, float height);
	// �ʱ� �ӷ��� ������ ����
	void Draw(HDC hdc) override;
};

class FallByGravity : public UniformMoving
{		// velocity�� �߷��� ������ ������ ����� UniformMoving�� �����ϹǷ�
public:
	void Move(Vector &velocity, float interval, float &locX, float &height) override;
};

class ObjList : public std::list<BaseObject *>
{
private:
	int regenRate;					// ������ Ȯ��
	std::list<BaseObject *> reserve;
public:
	ObjList();

	void AirplainRegen();
	void Draw(HDC hdc);
	void Routine();
	void PushBackReserve(BaseObject *obj);
	// ���� ���� ����Ʈ�� ���� ���� reserve�� �����ϰ� �ִٰ� ���߿� ó��
};