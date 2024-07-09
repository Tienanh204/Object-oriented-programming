
#include"Product.h"

string ProductInput::getID() {
	return ID;
}
string ProductInput::getName() {
	return Name;
}
float ProductInput::getPrice() {
	return Price;
}
Date ProductInput::getExDate()
{
	return ExDate;
}

void ProductInput::setID(string val)
{
	ID = val;
}
void ProductInput::setName(string val)
{
	Name = val;
}
void ProductInput::setPrice(float val)
{
	Price = val;
}

void ProductInput::input()
{
	cout << "ID: "; getline(cin, ID);
	cout << "Name: "; getline(cin, Name);
	cout << "Price: "; cin >> Price;
	cout << "Expiry date: ";
	int day, month, year; cin >> day >> month >> year;
	ExDate = Date(day, month, year);
}

void ProductInput::output()
{
	cout << "ID: " << ID << endl;
	cout << "Name: " << Name << endl;
	cout << "Price: " << Price << endl;
	cout << "Expiry date: " << ExDate.getDay() << "/" << ExDate.getMonth()
		<< "/" << ExDate.getYear() << endl;
}