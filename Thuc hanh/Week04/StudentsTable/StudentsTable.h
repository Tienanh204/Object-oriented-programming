#pragma once
#include<iostream>
#include<vector>
#include<math.h>
#include<string>
#include<sstream>
#include <iomanip>
using namespace std;

class Student {
public:
    string _no;
    string _id;
    string _fullname;
    string _email;
public:
    Student();
    Student(string id, string fullname, string email);
};


class StudentsToTableConverter {
private:
    vector<string> _headers;
    vector<int> _columnSizes;
public:
    StudentsToTableConverter() {};
    StudentsToTableConverter(vector<string> headers,
    vector<int> columnSizes);
    string convert(vector<Student> students);
private: // Inner class
    class StudentToRowConverter {
    private:
        vector<int> _columnSizes;
    public:
        StudentToRowConverter() {};
        StudentToRowConverter(vector<int> columnSizes) :_columnSizes(columnSizes) {};
        string convert(Student student);
    };
};

