#include "stdafx.h"
#include <iostream>
using namespace std;
using namespace System;

const int OVERTIME = 8;	// 초과 근무 시간

class PartTimer
{
private:
	int hourlyWage;	// 시급
	int workTime[7] = { 6, 10, 5, 9, 7, 5, 4 };
	//					월 화 수 목 금 토 일 근무시간
public:
	PartTimer()
	{
		hourlyWage = 7530;	// 시급 최저 시급 7530원으로 설정
	}

	int CalcDayPay(int workTime)	// 일일 급여 계산
	{
		// 일일 급여 = 일한 시간 * 시급 
		return  workTime * hourlyWage;
	}

	int CalcOverTime(int workTime)
	{	// 초과 근무는 일일 급여 * 1.5배로 계산
		return workTime * hourlyWage * 1.5;
	}

	int CalcWeekPay()	// 기본 주급 계산
	{
		int weeklyWage = 0;
		for (int week = 0; week < 7; ++week)
		{
			// 주급 = CalcDayPay(요일 별 일한 시간)
			weeklyWage += CalcDayPay(workTime[week]);
		}
		return weeklyWage;
	}
	// 저장을 월 화 수 목 ... 순으로 저장된다 가정
	// 토요일, 일요일은 5의 배수 또는 6의 배수
	bool IsWeek(int week)
	{
		return ( (week+1) % 6 == 0 || (week+1) % 7 == 0);
	}
	int CalcOverTimeWeekPay()	// 초과 근무 시간 계산
	{
		int weeklyWage = 0;
		for (int week = 0; week < 7; ++week)
		{	// 주급 = CalcDayPay(요일 별 일한 시간)
			if (IsWeek(week))
				// 초과 근무 계산
				weeklyWage += CalcOverTime(workTime[week]);
			else
				weeklyWage += CalcDayPay(workTime[week]);
		}
		return weeklyWage;
	}
	
	int CalcComplePay()	// 초과 근무 시간 계산
	{
		int weeklyWage = 0;
		for (int week = 0; week < 7; ++week)
		{
			int time = workTime[week];
			// 저장을 월 화 수 목 ... 순으로 저장된다 가정
			// 토요일, 일요일은 5의 배수 또는 6의 배수
			if (IsWeek(week))
			{	// 초과 근무 계산
				weeklyWage += CalcOverTime(time);
			}
			else
			{
				if (time >= OVERTIME)	// 일 OVERTIME시간 근무를 이상인 경우
				{
					weeklyWage += CalcDayPay(OVERTIME); // 8시간 까지는 일반 근무
					weeklyWage += CalcOverTime(time - OVERTIME);	// 8시간 이상 부터는 초과 근무
				}
				else
					weeklyWage += CalcDayPay(time);

			}
		}
		return weeklyWage;
	}

};
int main()
{
	PartTimer partTimer;
	cout << "1. 최저시급 7530원으로 계산한 결과를 출력하라." << endl;
	cout << "주급 : " << partTimer.CalcWeekPay() << "원" << endl;
	cout << endl;

	cout << "2. 토요일과 일요일 근무는 초과근무로 1.5배로 계산한 결과를 출력" << endl;
	cout << "주급 : " << partTimer.CalcOverTimeWeekPay() << "원" << endl;
	cout << endl;

	cout << "3. 하루 8시간 기준으로 그 이상 근무는 1.5배로 계산한 결과를 출력" << endl;
	cout << "주급 : " << partTimer.CalcComplePay() << "원" << endl;
	cout << endl;
    return 0;
}