#include<iostream>
using namespace std;


class PointInput
{
private:
	float x, y;
public:

	PointInput()
	{
		x = 0, y = 0;
	}
	int getX();
	int getY();

	void setX(int newX);
	void setY(int newY);

	void input();
	void output();

	~PointInput();
};