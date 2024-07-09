#include"IntegersInput.h"

IntergersInput::IntergersInput()
{
	n = 0;
}

void IntergersInput::randInterger()
{
	n = rand.next(10, 20);
}

void IntergersInput::inputArr()
{
	cout << "Please enter " << n << " integers in the range of[20, 100]" << endl;
	for (int i = 0; i < n; i++)
	{
		int x;
		do
		{
			cout << "Integer " << i + 1 << ": ";
			cin >> x;
			if (x < 20 || x>200)
			{
				cout << "Invalid input. Try again!" << endl;
			}
		} while (x < 20 || n>200);
		Arr.add(x);
	}
}

bool IntergersInput::Prime(int n)
{
	if (n < 2)
		return false;
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}

void IntergersInput::printPrime()
{
	int cnt = 0;
	int res[1000] = { 0 };

	for (int i = 0; i < n; i++)
	{
		if (Prime(Arr[i]))
		{
			cnt++;
			res[Arr[i]]++;
		}
	}
	if (cnt != 0)
	{
		cout << "Found " << cnt << " prime number(s): ";
		for (int i = 0; i < n; i++)
		{
			if (res[Arr[i]] != 0)
			{
				cout << Arr[i] << " ";
				res[Arr[i]] = 0;
			}
		}
	}
	else
	{
		cout << "Not found prime number(s)" << endl;
	}
}
