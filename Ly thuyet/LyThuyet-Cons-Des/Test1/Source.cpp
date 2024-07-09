#include"Function.h"


Triangle::Triangle() : A(0, 0), B(0, 1), C(1, 0)
{
	cout << "Triangle - Default cons" << endl;
}


Triangle::~Triangle() {
	cout << "Triangle - Des" << endl;
}

void Triangle::output() {
	cout << "A: ";
	A.output();
	cout << "; ";


	cout << "B: ";
	B.output();
	cout << "; ";


	cout << "C: ";
	C.output();
	cout << "; ";
}

void Point2D::input() {
	cout << "Nhap x, y: ";
	cin >> x >> y;
}


void Point2D::output() {
	cout << "(" << x << ", " << y << ")";
}


Point2D::Point2D() {
	cout << "Point2D - Default cons" << endl;
	x = 0;
	y = 0;
}
Point2D::Point2D(int a, int b) {
	cout << "Point2D - Cons with 2 args" << endl;
	x = a;
	y = b;
}


Point2D::Point2D(int val)
{
	cout << "Point2D - Cons with 1 arg" << endl;
	x = val;
	y = val;
}
