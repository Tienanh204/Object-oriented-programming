#include"FractionsProvider.h"

int Fraction::getNumerator() {
    return num;
}

int Fraction::getDenominator() {
    return den;
}

void Fraction::setNumerator(int value) {
    num = value;
}

void Fraction::setDenominator(int value) {
    den = value;
}

Fraction::Fraction()
{
	num = 0;
	den = 1;
}

Fraction::Fraction(int _num, int _den) {
    this->num = _num;
    this->den = _den;
}

FractionsProvider::FractionsProvider()
{
	n = 0;
}

void FractionsProvider::randInterger()
{
    n = rand.next(10,20);
}

bool FractionsProvider::checkFormat(string str) {
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

int Integer::findGCD(int a, int b) {
    if (b == 0)
        return a;
    return findGCD(b, a % b);
}

void FractionsProvider::inputArr()
{
    cout << "Please enter " << n << " fractions from the keyboard" << endl;
    for (int i = 0; i < n; i++)
    {
        bool check = true;
        string buffer = "";
        do
        {
            cout << "Fraction " << i + 1 << ": ";
            getline(cin, buffer);
            check = checkFormat(buffer);

            if (!check)
            {
                cout << "Phan so khong hop le" << endl;
                buffer = "";
            }
        } while (!check);

        stringstream ss(buffer);
        string num = "", den = "";
        getline(ss, num, '/');
        getline(ss, den);

        int x = 0, y = 0;
        x = stoi(num);
        y = stoi(den);
        Arr.add(Fraction(x,y));
    }
}

void FractionsProvider::printFraction() {

    Integer itg;
    cout << "All entered fractions: ";
    for (int i = 0; i < n; i++)
    {
        int num = Arr[i].getNumerator();
        int den = Arr[i].getDenominator();

        int integerPart = num/ den;
        int residualPart = num % den;

        int gcd = itg.findGCD(num, den);

        num = num/ gcd;
        den = den / gcd;

        if (residualPart == 0) {
            cout << integerPart;
        }
        else if (integerPart == 0) {
            cout << num << "/" << den;
        }
        else
        {
            cout << integerPart << " " << residualPart / gcd << "/" << den;
        }
        if (i <= n - 2)
        {
            cout << ", ";
        }
    }
}
