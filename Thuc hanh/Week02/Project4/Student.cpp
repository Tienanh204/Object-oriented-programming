#include"Student.h"

string StudentInput::getID()
{
	return ID;
}
string StudentInput::getName()
{
	return Name;
}
string StudentInput::getAddress()
{
	return Address;
}
string StudentInput::getEmail()
{
	return Email;
}
DATE StudentInput::getDOB()
{
	return dob;
}

void StudentInput::setID(string val)
{
	ID = val;
}
void StudentInput::setName(string val)
{
	Name = val;
}
void StudentInput::setAddress(string val)
{
	Address = val;
}
void StudentInput::setEmail(string val)
{
	Email = val;
}
void StudentInput :: setDOB(int d, int m, int y)
{
	dob = DATE(d, m, y);
}

void StudentInput::input()
{
	cout << "ID: "; getline(cin, ID);
	cout << "Name: "; getline(cin, Name);
	cout << "Address: "; getline(cin, Address);
	cout << "Email: "; getline(cin, Email);
	cout << "DOB: ";
	int d, m, y; cin >> d >> m >> y;
	dob = DATE(d, m, y);
}

void StudentInput::ouput()
{
	cout << "ID: " << ID << endl;
	cout << "Name: " << Name << endl;
	cout << "Address: " << Address << endl;
	cout << "Email: " << Email << endl;
	cout << "DOB: " << dob.getDay() << "/" << dob.getMonth()
		<< "/" << dob.getYear() << endl;
}

