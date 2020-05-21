#include "Flight.h"
#define COUNT_FLIGHTS 5


Flight::Flight(int number, string departure, string destination, Time start, Time end)
{
	this->setNumber(number);
	this->setDeparture(departure);
	this->setDestination(destination);
	this->setTimeStart(start);
	this->setTimeEnd(end);
}

Flight::Flight()
{
	this->setNumber(0);
	this->setDeparture("Unknown");
	this->setDestination("Unknown");
	this->setTimeStart(Time());
	this->setTimeEnd(Time());
}

int Flight::getNumber()
{
	return this->number;
}

string Flight::getDeparture()
{
	return this->departure;
}

string Flight::getDestination()
{
	return this->destination;
}

Time Flight::getTimeStart()
{
	return this->start;
}

Time Flight::getTimeEnd()
{
	return this->end;
}

void Flight::setNumber(int number)
{
	if (number < 0)
	{
		throw exception("Number must be greater than one.");
	}
	this->number = number;
}

void Flight::setDeparture(string departure)
{
	this->departure = departure;
}

void Flight::setDestination(string destination)
{
	this->destination = destination;
}

void Flight::setTimeStart(Time start)
{
	this->start = start;
}

void Flight::setTimeEnd(Time end)
{
	if (end.getYear() < this->getTimeStart().getYear())
	{
		throw exception("The year must be the current!");
	}
	else	
	{
		if ((end.getMonth() == this->getTimeStart().getYear())
			&& (end.getMonth() < this->getTimeStart().getMonth()))
		{
			throw exception("The month must be current and future!");
		}
		else
		{
			if ((end.getDay() == this->getTimeStart().getYear())
				&& (end.getDay() < this->getTimeStart().getDay()))
			{
				throw exception("The day must be current and future!");
			}
			else
			{
				if ((end.getHours() == this->getTimeStart().getYear())
					&& (end.getHours() < this->getTimeStart().getHours()))
				{
					throw exception("The hours must be from 7am!");
				}
			}
		}

	}
	this->end = end;
}

int Flight::getFlightTimeMinutes()
{
	return this->getTimeEnd().getHours() * 60 + this->getTimeEnd().getMinute() -
		(this->getTimeStart().getHours() * 60 + this->getTimeStart().getMinute());
}

void DemoFlightWithTime()
{
	Flight* flights = new Flight[COUNT_FLIGHTS];
	flights[0] = Flight(1, "Zimbabwe", "UK", Time(2009, 2, 4, 5, 21), Time(2009, 2, 4, 5, 20));
	flights[1] = Flight(2, "Russia", "USA", Time(2013, 1, 6, 5, 31), Time(2013, 1, 6, 5, 22));
	flights[2] = Flight(3, "Sweden", "Zimbabwe", Time(2005, 6, 4, 8, 21), Time(2005, 6, 4, 8, 18));
	flights[3] = Flight(4, "Zimbabwe", "UK", Time(2019, 2, 4, 5, 31), Time(2019, 2, 9, 5, 20));
	flights[4] = Flight(5, "Zimbabwe", "UK", Time(2020, 2, 4, 5, 15), Time(2020, 2, 4, 5, 20));

	for (int i = 0; i < COUNT_FLIGHTS; i++)
	{
		cout<<"Flight no: " <<flights[i].getNumber()<< " "
			<< flights[i].getDeparture() << "-" << flights[i].getDestination()
			<< " Start " << flights[i].getTimeStart().getDay() << "."
			<< flights[i].getTimeStart().getMonth() << " "
			<< flights[i].getTimeStart().getHours() << ":"
			<< flights[i].getTimeStart().getMinute() << "  "
			<< flights[i].getTimeEnd().getDay() << "."
			<< flights[i].getTimeEnd().getMonth() << " "
			<< flights[i].getTimeEnd().getHours() << ":" <<
			flights[i].getTimeEnd().getMinute() << endl;
	}
	for (int i = 0; i < COUNT_FLIGHTS; i++)
	{
		cout << "¹:" << flights[i].getNumber() << " "
			<< flights[i].getDeparture() << "-"
			<< flights[i].getDestination() << " Arrived: "
			<< flights[i].getFlightTimeMinutes() / 60 << "÷ "
			<< flights[i].getFlightTimeMinutes() % 60 << "  " << endl;
	}

	delete[] flights;
}


	
