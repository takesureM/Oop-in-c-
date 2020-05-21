#pragma once
#include "Time.h"

class Flight
{
public:
	void setNumber(int number);
	void setDeparture(string departure);
	void setDestination(string destination);
	void setTimeStart(Time start);
	void setTimeEnd(Time end);

	int getNumber();
	string getDeparture();
	string getDestination();
	Time getTimeStart();
	Time getTimeEnd();

	int getFlightTimeMinutes();

	Flight(int number, string departure, string destination, Time start, Time end);
	Flight();

private:
	int number;
	string departure;
	string destination;
	Time start;
	Time end;
};

void DemoFlightWithTime();
