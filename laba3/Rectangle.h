#pragma once
#include "Point.h"
#include <exception>
#include <iostream>

using namespace std;

class Rectangle
{
public:
	void setLength(double length);
	void setWidth(double width);
	void setCenter(Point point);

	double getLength();
	double getWidth();
	Point getCenter();

	Rectangle(double length, double width, Point center);
	Rectangle();

private:
	double length;
	double width;
	Point center;

};

void DemoRectangleWithPoint();
