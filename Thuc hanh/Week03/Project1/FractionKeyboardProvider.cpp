#include "FractionKeyboardProvider.h"

Fraction FractionKeyboardProvider::next(){

    Fraction fraction;
    bool check = true;
    string buffer = "";

    do
    {
        cout << "Nhap phan so a/b: ";
        getline(cin, buffer);
        check = fraction.checkFormat(buffer);

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

    Fraction result(stoi(num), stoi(den));
    return result;
}