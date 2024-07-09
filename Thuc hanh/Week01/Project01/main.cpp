#include"main.h"

int DeathLoop()
{
	int val = 0;
	while (true)
	{
		cout << "Enter an integer between 1 and 10: ";
		string tempValue;
		getline(cin, tempValue);

		if (tempValue.empty())
		{
			cout << "You did not enter anything. Please try again." << endl;
			continue;
		}
		istringstream ss(tempValue);
		ss >> val;
		if (ss.fail() || !ss.eof())
		{
			cout << "Invalid input. Please enter an integer value without any other characters." << endl;
			continue;
		}

		if (val < 1 || val>10)
		{
			cout << "Integer must be in the range [1, 10]. Please try again." << endl;
			continue;
		}
		return val;
	}
}

int main()
{
	cout << DeathLoop() << endl;
}