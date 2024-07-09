#include"main.h"

void CurrencyDisplay()
{
	string moneyVND = "";
	int exRate = 0;
	do
	{
		cout << "Enter an integer money: ";
		cin >> moneyVND;
		if (stoi(moneyVND) < 1000000 || stoi(moneyVND)>10000000)
		{
			cout << "Please. Enter an integer money in the range of [1.000.000, 10.000.000]" << endl;
		}
	} while (stoi(moneyVND) < 1000000 || stoi(moneyVND) > 10000000);

	do
	{
		cout << "Enter the exchange rate for 1USD: ";
		cin >> exRate;
		if (exRate != 25500)
		{
			cout << "The current exchange rate for 1 USD is 25,500. Please try again."<< endl;
		}
	} while (exRate != 25500);

	float moneyUSD;
	moneyUSD = 1.0*stoi(moneyVND) /exRate;

	string resVND = "";
	int cnt = 1;
	for (int i = moneyVND.size() - 1; i >= 0; i--)
	{
		resVND += moneyVND[i];
		if (cnt % 3 == 0)
		{
			resVND += ".";
		}
		cnt++;
	}
	reverse(resVND.begin(), resVND.end());

	cout << resVND << " d = $ ";
	cout << fixed << setprecision(2) << moneyUSD << endl;
}

int main()
{
	CurrencyDisplay();
}