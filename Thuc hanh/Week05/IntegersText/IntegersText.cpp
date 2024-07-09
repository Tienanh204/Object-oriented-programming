#include"IntegersText.h"

void Integer::displayResult()
{
	int n = result.size();
	cout << "Working with integer arrays from text files" << endl << endl;
	cout << "Reading data from input.txt." << endl;
	cout << "Expected to find " << n << " numbers." << endl << endl;

	if (n != 0)
	{
		cout << "Found " << n << " numbers: ";
		for (int i = 0; i < n; i++)
		{
			cout << result[i] << " ";
		}
	}
	else
	{
		cout << "Found " << n << " numbers";
	}
	cout << endl;
	int checkOdd = 0;
	int checkEven = 0;
	int checkPalindromic = 0;
	int checkPrime = 0;
	int checkSquare = 0;
	int checkPerfect = 0;

	for (int i = 0; i < n; i++)
	{
		if (oddNumber(result[i]))
			checkOdd++;

		if (evenNumber(result[i]))
			checkEven++;

		if (palindromicNumber(result[i]))
			checkPalindromic++;

		if (primeNumber(result[i]))
			checkPrime++;

		if (squareNumber(result[i]))
			checkSquare++;

		if (perfectNumber(result[i]))
			checkPerfect++;
	}

	int temp = 0;
	if (checkOdd != 0)
	{
		temp = checkOdd;
		cout << "Found " << checkOdd << " odd numbers: ";
		for (int i = 0; i < n; i++)
		{
			if (oddNumber(result[i]))
			{
				cout << result[i];
				temp--;
				if (temp > 0)
				{
					cout << ", ";
				}
			}

		}
	}
	else
	{
		cout << "Found " << checkOdd << " odd numbers";
	}
	cout << endl;

	if (checkEven != 0)
	{
		temp = checkEven;
		cout << "Found " << checkEven << " even numbers: ";
		for (int i = 0; i < n; i++)
		{
			if (evenNumber(result[i]))
			{
				cout << result[i];
				temp--;
				if (temp > 0)
				{
					cout << ", ";
				}
			}
		}
	}
	else
	{
		cout << "Found " << checkEven << " even numbers:";
	}
	cout << endl;

	if (checkPalindromic != 0)
	{
		temp = checkPalindromic;
		cout << "Found " << checkPalindromic << " palindromic number: ";
		for (int i = 0; i < n; i++)
		{
			if (palindromicNumber(result[i]))
			{
				cout << result[i];
				temp--;
				if (temp > 0)
				{
					cout << ", ";
				}
			}
		}
	}
	else
	{
		cout << "Found " << checkPalindromic << " palindromic number";
	}
	cout << endl;

	if (checkPrime != 0)
	{
		temp = checkPrime;
		cout << "Found " << checkPrime << " prime numbers: ";
		for (int i = 0; i < n; i++)
		{
			if (primeNumber(result[i]))
			{
				cout << result[i];
				temp--;
				if (temp > 0)
				{
					cout << ", ";
				}
			}
		}
	}
	else
	{
		cout << "Found " << checkPrime << " prime numbers";
	}
	cout << endl;

	if (checkSquare != 0)
	{
		temp = checkSquare;
		cout << "Found " << checkSquare << " square number: ";
		for (int i = 0; i < n; i++)
		{
			if (squareNumber(result[i]))
			{
				cout << result[i];
				temp--;
				if (temp > 0)
				{
					cout << ", ";
				}
			}
		}
	}
	else
	{
		cout << "Found " << checkSquare << " square number";
	}
	cout << endl;

	if (checkPerfect != 0)
	{
		temp = checkPerfect;
		cout << "Found " << checkPerfect << " perfect number: ";
		for (int i = 0; i < n; i++)
		{
			if (perfectNumber(result[i]))
			{
				cout << result[i];
				temp--;
				if (temp > 0)
				{
					cout << ", ";
				}
			}
		}
	}
	else
	{
		cout << "Found " << checkPerfect << " perfect number";
	}
	cout << endl;

	cout << "Minimum value: " << minValue() << endl;
	cout << "Maximum value: " << maxValue() << endl;
	cout << "Average value: " << fixed << setprecision(1) << averageValue() << endl;
	cout << "Sum of all numbers: " << sumNumber() << endl << endl;
	cout << "Program is exiting. Press enter to quit..." << endl;
}

int Integer::parse(string info)
{
	return stoi(info);
}

void Integer::setVector(vector<int> _result)
{
	for (int i = 0; i < _result.size(); i++)
	{
		result.push_back(_result[i]);
	}
}

bool Integer::oddNumber(int val)
{
	return val % 2 != 0;
}

bool Integer::evenNumber(int val)
{
	return val % 2 == 0;
}

bool Integer::numRever(int val)
{
	int res = 0, nRem = 0;
	int temp = val;

	while (temp != 0)
	{
		nRem = temp % 10;
		res = (res * 10) + nRem;
		temp = temp / 10;
	}
	return res == val;
}
//Vua la so nguyen to, va la so doi xuong
bool Integer::palindromicNumber(int val)
{
	return primeNumber(val) && numRever(val);
}

bool Integer::primeNumber(int val)
{
	if (val < 2)
		return false;
	for (int i = 2; i <= sqrt(val); i++)
	{
		if (val % i == 0)
			return false;
	}
	return true;
}

bool Integer::squareNumber(int val)
{
	if (val < 0)
		return false;
	int res = sqrt(val);
	return val == res * res;
}

bool Integer::perfectNumber(int val)
{
	int res = 0;
	for (int i = 1; i <= val/2; i++)
	{
		if (val % i == 0)
		{
			res += i;
		}
	}
	return val == res;
}

int Integer::minValue()
{
	int valMin = result[0];
	for (int i = 1; i < result.size(); i++)
	{
		if (valMin > result[i])
			valMin = result[i];
	}
	return valMin;
}

int Integer::maxValue()
{
	int valMax = result[0];
	for (int i = 1; i < result.size(); i++)
	{
		if (valMax < result[i])
			valMax = result[i];
	}
	return valMax;
}

double Integer::averageValue()
{
	int n = result.size();
	int sum = 0;
	for (int i = 0; i < result.size(); i++)
	{
		sum += result[i];
	}
	return sum * 1.0 / n;
}

int Integer::sumNumber()
{
	int sum = 0;
	for (int i = 0; i < result.size(); i++)
	{
		sum += result[i];
	}
	return sum;
}