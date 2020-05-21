#include "Point.h"

Point::Point(double x, double y)
{
	this->SetX(x);
	this->SetY(y);
}

Point::Point()
{
	this->SetX(0);
	this->SetY(0);
}


double Point::GetX()
{
	return this->_x;
}

double Point::GetY()
{
	return this->_y;
}

void Point::SetX(double x)
{
	this->_x = x;
}

void Point::SetY(double y)
{
	this->_y = y;
}