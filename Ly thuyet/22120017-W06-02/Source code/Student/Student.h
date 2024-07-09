#pragma once
#define _Student_h
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <string>
#include <fstream>
#include <map>
#include<iomanip>
#include <set>
#include <random>
#include <sstream>
using namespace std;

class Student {
private:
	string ID;
	int count;
public:
	friend istream& operator >> (istream& in, Student& s);
	Student();
	Student(string _ID, int _count);//Bo sung
	string getStudentCode();
	int getCount();
	void setStudentCode(string _ID);
	void setCount(int _count);
};


