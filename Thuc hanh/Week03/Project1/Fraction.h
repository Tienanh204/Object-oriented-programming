#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include<sstream>
#include <iomanip>
using namespace std;

class Fraction {
private:
    int _num;
    int _den;
public:
    int getNumerator();
    int getDenominator();
    void setNumerator(int value);
    void setDenominator(int value);
public:
    Fraction();
    Fraction(int num, int den);
    string toString();

    bool checkFormat(string str);

    void lowestTermMixed();
    void Decimal();
    void Percentage();
};

class Integer {
public:
    static int findGCD(int a, int b);
};

