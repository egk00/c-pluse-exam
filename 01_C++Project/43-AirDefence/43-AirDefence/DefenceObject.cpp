#include "stdafx.h"
#include "DefenceObject.h"

///////////////////////
// ������
///////////////////////

BaseObject::BaseObject(float locX, float height, float degree, float speed)
	:velocity(degree, speed)
{
	this->locX = locX;
	this->height = height;
	this->behavior = nullptr;
	this->lastMoveTime = timeGetTime();		// ���� ������� �ð�
}

BaseObject::~BaseObject()
{
	if (behavior != nullptr)
		delete behavior;
}

Matrix31 Airplain::lines[3][2];
bool Airplain::initializeComplate;
Airplain::Airplain(float height)	// ���̽� Ŭ���� ������ ȣ��
	: BaseObject(0, height, 90, airplainSpeedPerSec)
{
	behavior = new UniformMoving();		// ������ ��ӿ�ϴ� �������� �����Ҵ�
	if (initializeComplate == false)
	{
		float half = airplainSize;
		// ������� 0��(���� ���� ��) �����
		// velocity �������� ȸ�������� �� ����� �� ����� ���´�.
		lines[0][0] = Matrix31(0, -half);
		lines[0][1] = Matrix31(0, half);

		lines[1][0] = Matrix31(-half / 2, 0);
		lines[1][1] = Matrix31(half / 2, 0);

		lines[2][0] = Matrix31(-half / 4, half);
		lines[2][1] = Matrix31(half / 4, half);

		initializeComplate = true;
	}
}

ObjList::ObjList()
{
	regenRate = 20;
}



/////////////////////////////
// ����� ����
/////////////////////////////
void ObjList::AirplainRegen()
{
	// ó���� ���ݾ� �����ٰ� ���� ���� ��������
	if (rand() % 100 < regenRate)		// 20% Ȯ��
	{
		float halfField = fieldHeight / 2;
		// ����� ����
		float height = rand() % (int)halfField + halfField;
		push_back(new Airplain(height));
		//this�� ���� �����ϴ�.
	}
	++regenRate;
}

//���� �������� ȸ���ϰ� �����̵��ϴ� ��Ʈ����
Matrix33 BaseObject::TranslateMatrix()
{
	// ���� �������� ȸ����Ű�� ��Ʈ����
	Matrix33 rotate;
	rotate.RotationMovement(velocity.GetDegree());

	// ���� ��ġ�� �����̵���Ű�� ��Ʈ����
	Matrix33 parallel;
	float locY = fieldHeight - height;
	parallel.ParallelMovement(locX, locY);

	//ȸ���ϰ� �̵��Ѵ�.
	return parallel * rotate;
}

/////////////////////////////
// �׸���
/////////////////////////////
void Airplain::Draw(HDC hdc)
{
	// ���̽��� BaseObject���� ���� ��ȯ ��Ʈ������
	// ��ǥ�� ��ȯ�ؼ� �׸���
	Matrix33 translate = TranslateMatrix();
	for (int ln = 0; ln < 3; ++ln)
	{
		Matrix31 move = translate * lines[ln][0];
		Matrix31 line = translate * lines[ln][1];

		MoveToEx(hdc, move.GetX(), move.GetY(), nullptr);
		LineTo(hdc, line.GetX(), line.GetY());
	}
}

void ObjList::Draw(HDC hdc)
{
	// ���Ⱑ �̹� ObjList�� �̹Ƿ� ObjList::iterator����
	// ObjList::�� ������ �� �ִ�.
	// ���� objList.begin()������ ���Ⱑ objList��ü
	// ���̹Ƿ� �׳� begin(), end()�� ��� ����
	for (iterator obj = begin(); obj != end(); ++obj)
	{
		(*obj)->Draw(hdc);
	}
}

///////////////////////////////////////
// ������
//////////////////////////////////////
void UniformMoving::Move(Vector &velocity, float interval, float &locX, float &height)
{
	// velocity�� �ӵ��� ��ӿ�� �ؼ� �� ����� locX, height�� �����ϴ� �Լ�

	// 1. velocity�� x, y������ ����� dx�� dy�� ������.
	float dx, dy;
	velocity.DeltaXY(dx, dy);

	// 2. ��� � ��ȭ ��ġ * dealtaTime
	locX += dx * interval;
	height -= dy * interval;


}


////////////////////////////////////
// ��ƾ
////////////////////////////////////

void BaseObject::Routine(ObjList & objList)
{
	// ������ Routine �Ǵ� ������� �������� �ð�
	long curTime = timeGetTime();
	float interval = (curTime - lastMoveTime) / 1000.0;

	// �����δ�.
	// interval�� velocity�� ���ο� ��ġ ���
	// Behavior ������ �ٸ� ��ü�� �̿��� ���̹Ƿ�
	if (behavior != nullptr)
	{
		behavior->Move(velocity, interval, locX, height);
	}
	// ���� BaseObject::Routine()���� �ϴ� �ൿ�� ��� ������Ʈ��
	// ����� �ൿ(�̵�)�̴�.
	// ������ ������Ʈ���� �ٸ� �ൿ�� �� �� ������, �� �ൿ��
	// ������Ʈ���� �������ؼ� ���Ǿ�� �Ѵ�.

	// �� ���� �ٸ� �ൿ
	//OtherRoutine(objList);		// �� ������Ʈ�鸶�� Ư���ϰ� �ؾ� �� �ൿ


	lastMoveTime = curTime;
}

void ObjList::Routine()
{
	for (iterator obj = begin(); obj != end(); ++obj)
	{
		(*obj)->Routine(*this);
		// �� �ݺ��ڸ� �̿��� �ݺ��� �ȿ��� �������
		// Bomb�� reserve����Ʈ�� �����Ǿ� ����
	}
	// �ݺ����� �ݺ��� ���� �Ŀ� reserve�� �ִ�
	// Bomb���� ����Ʈ�� �߰�
	for (iterator resv = reserve.begin(); resv != reserve.end(); ++resv)
	{
		push_back(*resv);
	}
	// ����Ʈ�� �ִ� �� �� �߰������Ƿ� ����Ʈ ����
	reserve.clear();
}
