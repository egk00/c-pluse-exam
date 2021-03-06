#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
using namespace System;

const int SUBJECTCOUNT = 3;	// 과목 수
const int STUDENTCOUNT = 5;	// 학생 수
struct ExamScore
{
	string name;// 학생이름
	int korea;	// 국어점수
	int english;// 영어점수
	int math;	// 수학점수
	int total;	// 총점
	float avg;	// 평균
	int rank_korea;	// 국어점수 석차
	int rank_english;	// 영어점수 석차
	int rank_math;	// 수학점수 석차
}studentInfo[] =
{
	{ "홍길동" , 87, 74, 89, },
	{ "일지매" , 73, 82, 65 },
	{ "흥부", 73, 65, 58 },
	{ "이몽룡", 87, 69, 32 },
	{ "심청", 79, 62, 89 }
};

void Input_Total_Avg()
{
	// 1. 각 학생들의 총점과 평균을 계산해서 total과 avg에 넣어라
	for (int studentNum = 0; studentNum < STUDENTCOUNT; ++studentNum)
	{
		studentInfo[studentNum].total = studentInfo[studentNum].korea 
			+ studentInfo[studentNum].english + studentInfo[studentNum].math;

		studentInfo[studentNum].avg = studentInfo[studentNum].total / 3.0;
	}
}

void Print_Total_Avg()
{
	// 2. 각 학생들의 이름과 각 과목 성적, 총점과 평균을 출력하라.
	cout << "각 학생들의 이름과 각 과목 성적, 총점과 평균을 출력" << endl;
	for (int studentNum = 0; studentNum < STUDENTCOUNT; ++studentNum)
	{
		cout << "이름 : " << studentInfo[studentNum].name << 
			"\t총점 :" << studentInfo[studentNum].total << 
			"\t평균 : " << studentInfo[studentNum].avg << endl;
	}
}

void PrintRank()
{
	for (int studentNum = 0; studentNum < STUDENTCOUNT; ++studentNum)
	{
		cout << "이름 : " << studentInfo[studentNum].name
			<< "\t국어 점수 : " << studentInfo[studentNum].korea 
			<< "\t석차 :" << studentInfo[studentNum].rank_korea
			<< "\t영어 점수 : " << studentInfo[studentNum].english 
			<< "\t석차 :" << studentInfo[studentNum].rank_english
			<< "\t수학 점수 : " << studentInfo[studentNum].math 
			<< "\t석차 :" << studentInfo[studentNum].rank_math << endl;
	}
}

// 3. 각 학생들 중에서 총점이 가장 높은 학생과 낮은 학생을 찾아 이름을 출력하라.
int High_Total_Num()
{
	int highTotalStudent = 0;	// 1. 첫번째 학생이 가장 점수가 높다고 가정
	// 2. 다른 학생들과 비교해서 더 높은 학생이 있으면 그 학생이 가장 높다고 가정
	for (int studentNum = 1; studentNum < STUDENTCOUNT; ++studentNum)
	{
		// 나의 점수보다 높다면 그 학생이 가장 높은 점수로 변경
		if (studentInfo[highTotalStudent].total < studentInfo[studentNum].total)
			highTotalStudent = studentNum;
	}
	return highTotalStudent;
}

int High_Total_Num(int student)
{
	int highTotalStudent = student;	// 1. 입력 학생이 가장 점수가 높다고 가정
	// 2. 다른 학생들과 비교해서 더 높은 학생이 있으면 그 학생이 가장 높다고 가정
	for (int studentNum = student + 1; studentNum < STUDENTCOUNT; ++studentNum)
	{
		// 나의 점수보다 높다면 그 학생이 가장 높은 점수로 변경
		if (studentInfo[highTotalStudent].total < studentInfo[studentNum].total)
			highTotalStudent = studentNum;
	}
	return highTotalStudent;
}

int Low_Total_Num()
{
	int LowTotalStudent = 0;	// 1. 첫번째 학생이 가장 점수가 낮다고 가정
	// 2. 다른 학생들과 비교해서 더 낮은 학생이 있으면 그 학생이 가장 낮다고 가정
	for (int studentNum = 1; studentNum < STUDENTCOUNT; ++studentNum)
	{
		// 나의 점수보다 높다면 그 학생이 가장 높은 점수로 변경
		if (studentInfo[LowTotalStudent].total > studentInfo[studentNum].total)
			LowTotalStudent = studentNum;
	}
	return LowTotalStudent;
}

// 4. 총점 순으로 정렬하여 이름과 총점을 출력하라.
void Swap(ExamScore &student1, ExamScore &student2)
{
	ExamScore temp = student1;
	student1 = student2;
	student2 = temp;
}

void SelectSort()	// 선택 정렬 
{
	for (int studentNum = 0; studentNum < STUDENTCOUNT; ++studentNum)
	{
		int highStudent = High_Total_Num(studentNum);
		if (studentInfo[studentNum].total < studentInfo[studentNum+1].total)	// 앞에 값이 작다면 둘이 교환
		{	// 0에서 부터 가장 총합이 가장 큰 학생을 찾아 위치 교환
			Swap(studentInfo[studentNum], studentInfo[highStudent]);
		}
	}
	cout << "총점 순으로 정렬하여 이름과 총점을 출력하라." << endl;
	Print_Total_Avg();
}

int CalcKoreaRank(int student)	// 학생의 석차를 계산하는 함수
{
	int studentRank = 1;	// 1. 첫번째 학생이 가장 점수가 높다고 가정
	// 2. 다른 학생들과 비교해서 더 높은 학생이 있으면 그 학생이 가장 높다고 가정
	for (int studentNum = 0; studentNum < STUDENTCOUNT; ++studentNum)	// 전체 학생을 반복문을 돌린다.
	{
		if (studentInfo[student].korea < studentInfo[studentNum].korea) // 나의 점수보다 높다면 석차 증가
		{
			++studentRank;
		}
	}
	return studentRank;
}

int CalcEnglishRank(int student)	// 학생의 석차를 계산하는 함수
{
	// 1. 첫번째 학생이 가장 점수가 높다고 가정
	int studentRank = 1;
	// 2. 다른 학생들과 비교해서 더 높은 학생이 있으면 그 학생이 가장 높다고 가정
	for (int studentNum = 0; studentNum < STUDENTCOUNT; ++studentNum)	// 전체 학생을 반복문을 돌린다.
	{
		if (studentInfo[student].english < studentInfo[studentNum].english) // 나의 점수보다 높다면 석차 증가
		{
			++studentRank;
		}
	}
	return studentRank;
}

int CalcMathRank(int student)	// 학생의 석차를 계산하는 함수
{
	// 1. 첫번째 학생이 가장 점수가 높다고 가정
	int studentRank = 1;
	// 2. 다른 학생들과 비교해서 더 높은 학생이 있으면 그 학생이 가장 높다고 가정
	for (int studentNum = 0; studentNum < STUDENTCOUNT; ++studentNum)	// 전체 학생을 반복문을 돌린다.
	{
		if (studentInfo[student].math < studentInfo[studentNum].math) // 나의 점수보다 높다면 석차 증가
		{
			++studentRank;
		}
	}
	return studentRank;
}

int main(void)
{
	Input_Total_Avg(); // 1. 각 학생들의 총점과 평균을 계산해서 total과 avg에 넣어라
	Print_Total_Avg();	// 2. 각 학생들의 이름과 각 과목 성적, 총점과 평균을 출력하라.
	cout << endl;

	// 3. 각 학생들 중에서 총점이 가장 높은 학생과 낮은 학생을 찾아 이름을 출력하라.
	cout << "각 학생들 중에서 총점이 가장 높은 학생과 낮은 학생을 찾아 이름을 출력" << endl;
	int highStudent = High_Total_Num();
	int lowStudent = Low_Total_Num();
	cout << "가장 높은 학생이름 : " << studentInfo[highStudent].name << endl;
	cout << "가장 낮은 학생이름 : " << studentInfo[lowStudent].name << endl;
	cout << endl;

	SelectSort();	// 4. 총점 순으로 정렬하여 이름과 총점을 출력하라.
	cout << endl;

	// 5. 각 학생에 대해 각 성적별 석차를 구해서 출력하라.
	cout << "각 학생에 대해 각 성적 별 석차를 구해서 출력하라." << endl;
	for (int studentNum = 0; studentNum < STUDENTCOUNT; ++studentNum)	// 석차 저장
	{
		studentInfo[studentNum].rank_korea = CalcKoreaRank(studentNum);
		studentInfo[studentNum].rank_english = CalcEnglishRank(studentNum);
		studentInfo[studentNum].rank_math = CalcMathRank(studentNum);
	}
	PrintRank();
	return 0;
}
