#pragma once
#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>
#include<algorithm>
#include<math.h>
#include<set>
#include<map>
#include <random>
#include <ctime>
#include<iomanip>
#include<string>

using namespace std;

class Student
{
private:
	string ID;
	int count;
public:
	Student();
	Student(string _id, int _count);
	//Setter
	void setID(string _id);
	void setCount(int _count);

	//Getter
	string getID();
	int getCount();
};

class Session
{
private:
	vector<Student> student;
public:
	vector<Student> randStudent;
	Session() {};
	Session(vector<Student> _student);

	void readFromCSV(string filename);

	void calculateProbability(string filename);

	string chooseRandomStudent();

	void removeStudent(string index);

	void updateFileCSV(string filename);
};

