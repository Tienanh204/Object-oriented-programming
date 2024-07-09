#include<iostream>
using namespace std;


class DateInput
{
private:
	int day;
	int month;
	int year;
public:

	DateInput()
	{
		day = 0, month = 0, year = 0;
	}
	
	int getDay();
	int getMonth();
	int getYear();

	void setDay(int val);
	void setMonth(int val);
	void setYear(int val);

	void input();
	void output();
};
