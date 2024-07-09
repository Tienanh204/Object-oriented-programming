#include"main.h"

void NextDay()
{
	time_t info = time(NULL);
	tm now;
	localtime_s(&now, &info);

	int year = now.tm_year + 1900;
	int month = now.tm_mon + 1;
	int day = now.tm_mday;

	cout << "Current date: ";
	cout << day << "/" << month << "/" << year << endl;

	day++;

	int dayInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
	{
		dayInMonth[1] = 29;
	}

	if (day > dayInMonth[month - 1])
	{
		day = 1;
		month++;

		if (month > 12)
		{
			month = 1;
			year++;
		}
	}
	cout << "Next date: ";
	cout << day << "/" << month << "/" << year;
}

int main()
{
	NextDay();
}