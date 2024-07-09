#define _POINT_H_
#include <iostream>
#include <vector>
using namespace std;


class Point2D {
private:
	int x, y;
public:
	Point2D();
	Point2D(int, int);
	Point2D(int);

	Point2D(Point2D&);
	// Point2D(Point2D); // error


	void input();
	void output();
};


class Triangle
{
private:
	Point2D A, B, C;
public:
	Triangle();
	~Triangle();
	void output();
};

