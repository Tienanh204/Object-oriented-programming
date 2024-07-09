#include<iostream>
using namespace std;


class LineInput
{
private:
	float x1, y1, x2, y2;
public:

	LineInput()
	{
		x1 = x2 = 0;
		y1 = y2 = 0;
	}

	int getX1();
	int getY1();
	int getX2();
	int getY2();

	void setX1(int val);
	void setY1(int val);
	void setX2(int val);
	void setY2(int val);

	void input();
	void ouput();
};