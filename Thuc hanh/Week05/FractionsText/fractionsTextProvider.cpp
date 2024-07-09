#include"FractionsText.h"
#include"fractionsTextProvider.h"

FractionsText FractionKeyboardProvider::getAll(string filename)
{
	FractionsText frac;
	ifstream fin;
	fin.open(filename + ".txt", ios::in);
	if (!fin)
	{
		cout << "Can't open file" << endl;
	}
	else
	{
		int n;
		fin >> n;
		string buffer = "";
		while (getline(fin, buffer))
		{
			bool check = frac.checkFormat(buffer);
			if (check)
			{
				stringstream ss(buffer);
				string num = "", den = "";
				getline(ss, num, '/');
				getline(ss, den);

				Fraction result(stoi(num), stoi(den));
				frac.setFraction(result);
			}
		}
	}
	return frac;
}