#include "Student.h"

Student::Student(string _ID, int _count)
{
	ID = _ID;
	count = _count;
}

istream& operator >> (istream& in, Student& s) {
	in >> s.ID >> s.count;
	return in;
}

Student::Student() {
	this->ID = "";
	this->count = 0;
}

std::string Student::getStudentCode() {
	return this->ID;
}

int Student::getCount() {
	return this->count;
}

void Student::setStudentCode(std::string _ID) {
	this->ID = _ID;
}

void Student::setCount(int _count) {
	this->count = _count;
}