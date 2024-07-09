#include"Point.h"

int PointInput :: getX() {
	return x; 
}

int PointInput:: getY() {
	return y; 
}

void PointInput::setX(int newX)
{
	x = newX;
}

void PointInput::setY(int newY)
{
	y = newY;
}

void PointInput::input()
{
	cout << "Nhap x: ";
	cin >> x;
	cout << "Nhap y: ";
	cin >> y;
}

void PointInput::output()
{
	cout << "(x,y): " << "(" << x 
		 << "," << y << ")" << endl;
}

PointInput::~PointInput()
{
	x = 0; y = 0;
}

