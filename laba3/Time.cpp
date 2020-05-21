#include "Time.h"

Time::Time(int year, int month, int day, int hours, int minute) 
{
	this->setYear(year);
	this->setMonth(month);
	this->setDay(day);
	this->setHours(hours);
	this->setMinute(minute);
}

Time::Time()
{
	this->setYear(0);
	this->setMonth(0);
	this->setDay(0);
	this->setHours(0);
	this->setMinute(0);
}

int Time::getYear()
{
	return this->_year;
}

int Time::getMonth()
{
	return this->_month;
}

int Time::getDay()
{
	return this->_day;
}

int Time::getHours()
{
	return this->_hours;
}

int Time::getMinute()
{
	return this->_minute;
}

void Time::setYear(int year)
{
	if (year < 0 || year > 2020)
	{
		throw exception("The year must not be less than current year!.");
	}
	this->_year = year;
}

void Time::setMonth(int month)
{
	if (month < 0 || month > 12)
	{
		throw exception("The month must be from 1 to 12!.");
	}
	this->_month = month;
}

void Time::setDay(int day)
{
	if (day < 0 || day > 30)
	{
		throw exception("The day must be less than 30!.");
	}
	this->_day = day;
}

void Time::setHours(int hours)
{
	if (hours < 0 || hours > 24)
	{
		throw exception("Hours must be from 1 to 24!.");
	}
	this->_hours = hours;
}

void Time::setMinute(int minute)
{
	if (minute < 0 || minute > 60)
	{
		throw exception("Minutes must be from 0 to 60!.");
	}
	this->_minute = minute;
}
