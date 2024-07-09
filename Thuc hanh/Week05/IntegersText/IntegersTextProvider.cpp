#include"IntegersText.h"
#include"IntegersTextProvider.h"

vector<int> IntegersTextProvider::read(string filename)
{
	ifstream fin;
	vector<int> result;
	fin.open(filename + ".txt", ios::in);
	if (!fin)
	{
		cout << "Can't not open file" << endl;
		return result;
	}

	int n;
	fin >> n;

	while (fin >> n)
	{
		result.push_back(n);
	}
	return result;
	fin.close();
}
