#include"main.h"

string Date()
{
	time_t info = time(NULL);
	tm now;
	localtime_s(&now, &info);

	int year = now.tm_year + 1900;
	int month = now.tm_mon + 1;
	int day = now.tm_mday;

	string newDay, newYear, newMon;
	newDay = string(2 - to_string(day).length(), '0') + to_string(day);
	newMon = string(2 - to_string(month).length(), '0') + to_string(month);
	
	int i = 2;
	while (i > 0)
	{
		int tmp = year % 10;
		newYear += to_string(tmp);
		year /= 10;
		i--;
	}
	reverse(newYear.begin(), newYear.end());

	return newYear + newMon + newDay;
}

void Logger(string content)
{
	string nanmeFile = "log-" + Date() + ".txt";
	ofstream fout;
	fout.open(nanmeFile, ios::app);

	if (!fout.is_open())
	{
		cout << "Can't open file: " << nanmeFile << endl;
		return;
	}
	cout << "Successfully wrote content to file." << endl;
	fout << content << endl;
}

int main()
{
	Logger("Iam Truong Tien ");
	return 0;
}
