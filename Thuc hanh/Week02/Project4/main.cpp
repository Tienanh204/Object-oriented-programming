#include"Student.h"


int main()
{
	StudentInput student;
	cout << "Input Student information" << endl;
	student.input();

	cout << endl;

	cout << "Output Student information" << endl;
	student.ouput();

	student.setDOB(1, 4, 5);
	student.ouput();

}