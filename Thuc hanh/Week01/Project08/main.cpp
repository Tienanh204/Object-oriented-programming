
#include"main.h"

void FractionToDouble()
{
	cout << "Fraction: ";
	string fraction;
	getline(cin, fraction);
	stringstream ss(fraction);

	string num, denom;
	getline(ss, num, '/');
	getline(ss, denom);

	if (stoi(denom) != 0)
	{
		float res = 1.0 * stoi(num) / stoi(denom);
		cout << fixed << setprecision(2) << res << endl;
	}
	else
	{
		cout << "Fraction invalid!" << endl;
	}

}

int main()
{
	FractionToDouble();
}