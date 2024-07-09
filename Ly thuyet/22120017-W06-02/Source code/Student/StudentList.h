#pragma once
#ifndef _StudentList_h
#define _StudentList_h

#include "Student.h"

class StudentList {
private:

	map<int, set<string>> student;
	map<int, set<string>> randStudent;

public:
	StudentList() {};//Bo sung
	StudentList(map<int, set<string>> _student, map<int, set<string>> _randStudent);//Bo sung
	map<int, set<string>> getStudent();
	map<int, set<string>> getRandStudent();

	//Random sinh vien theo source code
	//StudentList(string filename);-> thay the bang: void readFromCSV(string filename)
	void readFromCSV(string filename);//Bo sung

	void randomStudentSource(bool replacement);
	void updateMpNew();
	void updateFileCSV(string filename);

	//Random sinhg vien theo  file config
	void calculateProbability(string filename);//Bo sung
	void randomStudentConfig(bool replacement);//Bo sung
};
#endif // !_StudentList_h

