#pragma once
#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<iomanip>
#include<math.h>
#include<sstream>
using namespace std;

class Fraction
{
private:
	int num;
	int den;

public:
	Fraction() :num(0), den(0) {};
	Fraction(int _num, int _den)
	{
		num = _num;
		den = _den;
	}

	int getNum() { return num; };
	int getDen() { return den; };
	void setNum(int val) { num = val; };
	void setDen(int val) { den = val; };

};

class FractionsText
{
private:
	vector<Fraction> fraction;
public:
	string toString(int i);
	void setFraction(Fraction frac) { fraction.push_back(frac); };

	bool checkFormat(string str);

	void displayFraction();
	void lowestTermMixed();
	void Decimal();
	void Percentage();
};

class Integer {
public:
	static int findGCD(int a, int b);
public:
};
