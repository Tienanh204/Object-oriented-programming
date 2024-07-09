#include"Line.h"

int LineInput::getX1()
{
	return x1;
}
int LineInput::getY1()
{
	return y1;
}
int LineInput::getX2()
{
	return x2;
}
int LineInput::getY2()
{
	return y2;
}

void LineInput::setX1(int val)
{
	x1 = val;
}
void LineInput::setY1(int val)
{
	y1 = val;
}
void LineInput::setX2(int val)
{
	x2 = val;
}
void LineInput::setY2(int val)
{
	y2 = val;
}
void LineInput::input()
{
	cout << "Nhap x1 y1 x2 y2: ";
	cin >> x1 >> y1 >> x2 >> y2;
}

void LineInput::ouput()
{
	cout << "(x1,y1): " << "(" << x1 << "," << y2 << ")" << endl;
	cout << "(x2,y2): " << "(" << x2 << "," << y2 << ")" << endl;
}
