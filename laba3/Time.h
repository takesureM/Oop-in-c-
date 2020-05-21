#pragma once
#include<exception>
#include<iostream>
using namespace std;

class Time
{
private:
	int _year;
	int _month;
	int _day;
	int _hours;
	int _minute;

public:
	void setYear(int year);
	void setMonth(int mounth);
	void setDay(int day);
	void setHours(int hours);
	void setMinute(int minute);

	int getYear();
	int getMonth();
	int getDay();
	int getHours();
	int getMinute();

	Time(int year, int month, int day, int hours, int minute);
	Time();
};




