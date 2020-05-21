#include"Rectangle.h"
#define COUNT_RECTANGLES 5

Rectangle::Rectangle(double length, double width, Point center)
{
	this->setLength(length);
	this->setWidth(width);
	this->setCenter(center);

}

Rectangle::Rectangle()
{
	this->setLength(0);
	this->setWidth(0);
	this->setCenter(Point());

}


void Rectangle::setLength(double length)
{
	if (length < 0)
	{
		throw exception("The length must be greater than zero");
	}
	this->length = length;
}

void Rectangle::setWidth(double width)
{
	if (width < 0)
	{
		throw exception("The width must be greater than zero");
	}
	this->length = width;
}

void Rectangle::setCenter(Point point)
{
	this->center = point;
}

Point Rectangle::getCenter()
{
	return this->center;
}

double Rectangle::getLength()
{
	return this->length = length;
}

double Rectangle::getWidth()
{
	return this->width = width;
}

void DemoRectangleWithPoint()
{
	Rectangle* rectangles = new Rectangle[COUNT_RECTANGLES];
	rectangles[0] = Rectangle(3, 4, Point(3, 4));
	rectangles[1] = Rectangle(4, 5, Point(4, 5));
	rectangles[2] = Rectangle(5, 6, Point(5, 6));
	rectangles[3] = Rectangle(6, 7, Point(6, 7));
	rectangles[4] = Rectangle(7, 8, Point(7, 8));

	double sumX = 0, sumY = 0;
	for (int i = 0; i < COUNT_RECTANGLES; i++)
	{
		cout << "X = " << rectangles[i].getCenter().GetX() << ";\t"
			<< "Y = " << rectangles[i].getCenter().GetY() << ";\t"
			<< "Length = " << rectangles[i].getLength() << ";\t"
			<< "Width = " << rectangles[i].getWidth() << "." << endl;

		sumX += rectangles[i].getCenter().GetX();
		sumY += rectangles[i].getCenter().GetY();
	}

	cout << "X = " << sumX / COUNT_RECTANGLES << ";\t"
		<< "Y = " << sumY / COUNT_RECTANGLES;

	delete[] rectangles;
}