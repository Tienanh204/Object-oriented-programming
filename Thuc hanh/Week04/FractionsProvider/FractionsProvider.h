#pragma once
#include"..\SupportFunction\DynamicArray.h"
#include"..\SupportFunction\RandomInteger.h"
#include<iostream>
#include<vector>
#include<string>
#include<math.h>
#include<sstream>

using namespace std;

class Fraction
{
private:
	int num;
	int den;
public:
	Fraction();
	Fraction(int _num, int _den);

	int getNumerator();
	int getDenominator();
	void setNumerator(int newNum);
	void setDenominator(int newDen);
};

class FractionsProvider
{
private:
	int n;
public:
	DynamicArray<Fraction> Arr;
	RandomInteger rand;

	FractionsProvider();

	void randInterger();
	void inputArr();
	bool checkFormat(string str);
	void printFraction();
};

class Integer
{
public:
	int findGCD(int a, int b);
};