#include"FractionsText.h"
#include"fractionsTextProvider.h"
using namespace std;

string FractionsText::toString(int i) {
    stringstream builder;
    builder << fraction[i].getNum() << "/" << fraction[i].getDen();

    string result = builder.str();
    return result;
}

bool FractionsText::checkFormat(string str) {
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


void FractionsText::displayFraction()
{
    int n = fraction.size();
    cout << "Working with fraction arrays from text files" << endl << endl;
    cout << "Reading data from input.txt." << endl;
    cout << "Expected to find " << n << " fractions" << endl << endl;
    cout << "Found " << n << " fraction: ";

    for (int i = 0; i < n; i++)
    {
        cout << toString(i);
        if (i <= n - 2)
        {
            cout << ", ";
        }
    }
    cout << endl;
}

int Integer::findGCD(int a, int b) {
    if (b == 0)
        return a;
    return findGCD(b, a % b);
}

void FractionsText::lowestTermMixed() {

    Integer itg;
    cout << "Lowest term: ";
    int n = fraction.size();
    for (int i = 0; i < n; i++)
    {
        int num_t1 = fraction[i].getNum();
        int den_t1 = fraction[i].getDen();

        int integerPart = num_t1 / den_t1;
        int residualPart = num_t1 % den_t1;

        int gcd = itg.findGCD(num_t1, den_t1);

        int temp = num_t1;

        num_t1 = num_t1 / gcd;
        den_t1 = den_t1 / gcd;

        if (num_t1 != temp)
        {
            cout << num_t1 << "/" << den_t1;
        }
        else if (residualPart == 0) {
            cout << integerPart;
        }
        else if (integerPart == 0) {
            cout << num_t1 << "/" << den_t1;
        }
        else
        {
            cout << integerPart << " " << residualPart / gcd << "/" << den_t1;
        }
        if (i <= n - 2)
        {
            cout << ", ";
        }
    }
    cout << endl;
}


void FractionsText::Decimal() {
    cout << "Decimal: ";
    int n = fraction.size();
    for (int i = 0; i < n; i++)
    {
        double res = static_cast<double>(fraction[i].getNum()) / fraction[i].getDen();
        cout << fixed << setprecision(2) << res;
        if (i <= n - 2)
        {
            cout << ", ";
        }
    }
    cout << endl;
}

void FractionsText::Percentage() {
    cout << "Percentage: ";
    int n = fraction.size();
    for (int i = 0; i < n; i++)
    {
        double res = static_cast<double>(fraction[i].getNum()) / fraction[i].getDen();
        cout << fixed << setprecision(0) << res * 100 << "%";
        if (i <= n - 2)
        {
            cout << ", ";
        }
    }
    cout << endl;
}