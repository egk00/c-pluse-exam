// 28-STL-vector.cpp : 기본 프로젝트 파일입니다.

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
using namespace System;

class IntClass
{
private:
	int value;
public:
	IntClass(int value)
	{
		this->value = value;
	}
	void Write()
	{
		cout << "Value : " << value << endl;
	}
};
int main()
{
	vector<IntClass> intClassVector;

	intClassVector.push_back(IntClass(6));
	intClassVector.push_back(IntClass(8));
	intClassVector.push_back(IntClass(1));

	// 벡터에 객체가 몇개가 추가되었는지 확인
	cout << "현재 intClassVector에는 " << intClassVector.size() << "개의 객체가 들어 있습니다." << endl;

	// 벡터에 저장된 객체 가져오기 - 배열과 동일
	for (int index = 0; index < intClassVector.size(); ++index)
	{
		intClassVector[index].Write();
	}
	cout << endl;

	// 이 상태에서는 크기 4짜리 배열과 동일하게 사용 가능
	intClassVector[1] = IntClass(12);
	// 벡터에 저장된 객체 가져오기 - 배열과 동일
	for (int index = 0; index < intClassVector.size(); ++index)
	{
		intClassVector[index].Write();
	}
	cout << endl;
	return 0;
}