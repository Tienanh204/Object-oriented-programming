
#define _POINT_H_
#include <iostream>
#include <vector>
using namespace std;

class Point2D
{
private:
	int x, y;
public:
	Point2D();
	Point2D(int, int);
	Point2D(int);
	void input();
	void output();

	Point2D(Point2D&);

	/*void input();
	void output();*/
	~Point2D();
};

void f1(Point2D p1);
void f2(Point2D& p1);