#include"Date.h"

int DateInput::getDay()
{
	return day;
}
int DateInput::getMonth()
{
	return month;
}
int DateInput::getYear()
{
	return year;
}

void DateInput::setDay(int val)
{
	if (val < 1 || val>30)
	{
		cout << "Day invalid!" << endl;
		return;
	}
	day = val;
}
void DateInput::setMonth(int val)
{
	if (val < 1 || val>12)
	{
		cout << "Month invalid!" << endl;
		return;
	}
	month = val;
}
void DateInput::setYear(int val)
{
	if (val < 1 )
	{
		cout << "Year invalid!" << endl;
		return;
	}
	year = val;
}

void DateInput::input()
{
	do
	{
		cout << "Day: "; cin >> day;
		if (day < 1 || day>30)
		{
			cout << "Day invalid!" << endl;
		}
	} while (day < 1 || day>30);

	do
	{
		cout << "Month: "; cin >> month;
		if (month < 1 || month>12)
		{
			cout << "Month invalid!" << endl;
		}
	} while (month < 1 || month>12);

	do
	{
		cout << "Year: "; cin >> year;
		if (year < 1)
		{
			cout << "Year invalid!" << endl;
		}
	} while (year < 1);
}

void DateInput::output()
{
	cout << "Date: " << day << "/" << month << "/" << year << endl;
}