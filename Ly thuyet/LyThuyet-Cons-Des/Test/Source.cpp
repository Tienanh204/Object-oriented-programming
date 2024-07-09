#include "Function.h"

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

void Point2D::input() {
	cout << "Nhap x, y: ";
	cin >> x >> y;
}


void Point2D::output() {
	cout << "(" << x << ", " << y << ")";
}

Point2D::~Point2D() {
	cout << "Point2D - Des" << endl;
}

// Copy constructor
Point2D::Point2D(Point2D& other) {
	cout << "Point2D - Copy cons" << endl;
	x = other.x;
	y = other.y;
}

//Coppy tu p3 ben kia
void f1(Point2D p1) {
	Point2D p2;
	p2.output();
}

void f2(Point2D& p1) {
	Point2D p2;
	p2.output();
}

