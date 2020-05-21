#pragma once

class Point
{
public:
	void SetX( double x);
	void SetY( double y);
	double GetX();
	double GetY();

	Point(double x, double y);
	Point();

private:
	double _x;
	double _y;

};

