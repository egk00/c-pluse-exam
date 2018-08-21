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

const float airplainSpeedPerSec = 100;			// ����� �ʼ�
const float airplainSize = 50;					// ����� ũ��

// Ÿ�̸� ����
const int Timer_AirplainRegen_ID = 1;			// ����� ���� ID
const int Timer_AirplainRegen_Interval = 1000;	// 1�� �������� ����

const int Timer_ObjectRoutine_ID = 2;			// �̹��� �� ������Ʈ���� �ؾ��� ��
const int Timer_ObjectRoutine_Interval = 50;

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
};


class Airplain : public BaseObject
{
private:
	static Matrix31 lines[3][2];		// �� ������ �Ϸ�
	static bool initializeComplate;

public:
	Airplain(float height);
	void Draw(HDC hdc) override;
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