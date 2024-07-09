#include<iostream>
#include<string>
using namespace std;

class DATE
{
private:
	int day, month, year;
public:
	DATE()
	{
		day = 0, month = 0, year = 0;
	}
	DATE(int d, int m, int y)
	{
		day = d;
		month = m;
		year = y;
	}
	int getDay() { return day; };
	int getMonth() { return month; };
	int getYear() { return year; };

	void setDay(int d) { day = d; };
	void setMonth(int m) { month = m; };
	void setYear(int y) { year = y; };

};

class StudentInput
{
private:
	string ID, Name, Address, Email;
	DATE dob;
public:
	StudentInput()
	{
		ID = "";
		Name = "";
		Address = "";
		Email = "";
		dob;
	}

	string getID();
	string getName();
	string getAddress();
	string getEmail();
	DATE getDOB();

	void setID(string val);
	void setName(string val);
	void setAddress(string val);
	void setEmail(string val);
	void setDOB(int d, int m, int y);

	void input();
	void ouput();
};
