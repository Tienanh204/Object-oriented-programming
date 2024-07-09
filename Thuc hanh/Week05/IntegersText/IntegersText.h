#pragma once
#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<iomanip>
#include<math.h>
using namespace std;

class Integer {
private:
	vector<int> result;
public:
	static int parse(string info);
public:
	void setVector(vector<int> _result);
	bool oddNumber(int val);
	bool evenNumber(int val);
	bool palindromicNumber(int val);
	bool primeNumber(int val);
	bool squareNumber(int val);
	bool perfectNumber(int val);
	bool numRever(int val);
	int minValue();
	int maxValue();
	double averageValue();
	int sumNumber();
	void displayResult();
};

