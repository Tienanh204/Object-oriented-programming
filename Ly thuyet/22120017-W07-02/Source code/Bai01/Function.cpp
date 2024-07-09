#include"Function.h"


BusinessGate::BusinessGate()
{
	price = 0;
	quantity = 0;
}

AcademicGate::AcademicGate()
{
	intellect = 0;
}

Power::Power()
{
	power = 0;
}

void BusinessGate::input()
{
	cout << "Price: "; cin >> price;
	cout << "Quantity: "; cin >> quantity;
}

int BusinessGate::getFeatureGate()
{
	return 1.0 * price * quantity;
}

void AcademicGate::input()
{
	cout << "Intelligence Quotient: "; cin >> intellect;
}
int AcademicGate::getFeatureGate()
{
	return intellect;
}

void Power::input()
{
	cout << "Power: "; cin >> power;
}
int Power::getFeatureGate()
{
	return power;
}
