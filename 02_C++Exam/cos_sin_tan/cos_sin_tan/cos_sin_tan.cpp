// cos_sin_tan.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include <math.h>
using namespace std;
const float pi = 3.14159265;
int main()
{
	float degreeValue = 30 + 180;	// 30도
	float radianValue = degreeValue / 180 * pi;	// (1/6) * pi => 30도 라디안으로 변경

	float radian = sin(radianValue);	// sin(30)의 결과는 라디안으로 출력
	cout << "sin(30) 결과 값 : "<<radian << endl;;

	float degree = sin(degreeValue * pi / 180);	// 30 * pi / 180 => degree를 라디안으로 변경
	cout << "sin(30 * 파이 / 180) 결과 값 : " << degree << endl;

	for (int dgr = 30; dgr <= 720; dgr+= 15)
	{
		cout.setf(ios::fixed);	// 소수점 아래 자리수 지정
		cout.precision(5);
		float sinValue = sin(dgr * pi / 180);
		float cosValue = cos(dgr * pi / 180);
		float tanValue = tan(dgr * pi / 180);

		cout << dgr << "도\t" << "sin 값 : " << sinValue << "\tcos 값 : " << cosValue  <<"\ttan 값 : " << tanValue << endl;
	}
	return 0;
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
