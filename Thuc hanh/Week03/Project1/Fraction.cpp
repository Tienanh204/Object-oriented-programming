#include "Fraction.h"
#include <sstream>

int Fraction::getNumerator() {
    return _num;
}

int Fraction::getDenominator() {
    return _den;
}

void Fraction::setNumerator(int value) {
    _num = value;
}

void Fraction::setDenominator(int value) {
    _den = value;
}

Fraction::Fraction() {
    _num = 0;
    _den = 1;
}

Fraction::Fraction(int num, int den) {
    _num = num;
    _den = den;
}

string Fraction::toString() {
    stringstream builder;
    builder << _num << "/" << _den;

    string result = builder.str();
    return result;
}

//Cau 1
bool Fraction::checkFormat(string str) {
    // Empty input
    if (str.empty())
        return false;

    // Invalid fraction format
    int cnt = 0;
    for (char c : str) {
        if (!isdigit(c) && c != '/') 
            return false;
        if (c == '/')
            cnt++;
    }
    if (cnt != 1)
        return false;

    stringstream ss(str);
    string num, den;
    getline(ss, num, '/');
    getline(ss, den);

    for (char c : num) {
        if (!isdigit(c))
            return false;
    }
    for (char c : den) {
        if (!isdigit(c))
            return false;
    }

    // Denominator is invalid (zero)
    int temp = stoi(den);
    if (temp == 0)
        return false;

    return true;
}

//Cau 2
//a)
int Integer::findGCD(int a, int b) {
    if (b == 0)
        return a;
    return findGCD(b, a % b);
}

void Fraction::lowestTermMixed() {

    Integer itg;
    int num_t1 = _num;
    int den_t1 = _den;

    int integerPart = num_t1 / den_t1;
    int residualPart = num_t1 % den_t1;

    int gcd = itg.findGCD(num_t1, den_t1);

    num_t1 = num_t1 / gcd;
    den_t1 = den_t1 / gcd;

    if (residualPart == 0){
        cout << integerPart << endl;
    }
    else if (integerPart == 0) {
        cout << num_t1 << "/" << den_t1 << endl;
    }
    else
    {
        cout << integerPart << " " << residualPart / gcd << "/" << den_t1 << endl;
    }
}

//b)
void Fraction::Decimal() {
    double res = static_cast<double>(_num) / _den;
    cout << fixed << setprecision(3) << res<< endl;
}

//c)
void Fraction::Percentage() {
    double res = static_cast<double>(_num) / _den;
    cout << fixed << setprecision(1) << res*100 <<"%" << endl;
}