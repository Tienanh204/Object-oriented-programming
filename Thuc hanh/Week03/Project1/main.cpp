#include <iostream>
#include "Fraction.h"
#include "FractionKeyboardProvider.h"

int main()
{
    cout << "Nhap xuat phan so\n\n";

    cout << "Nhap vao mot phan so.\n";

    FractionKeyboardProvider provider;
    Fraction a = provider.next();
    cout << "\n";
    cout << "Phan so vua nhap la:"
        << a.toString();
    cout << "\n\n";
    cout << "Lowest term & mixed: ";
    a.lowestTermMixed();
    cout << "Decimal: ";
    a.Decimal();
    cout << "Percentage: ";
    a.Percentage();

}