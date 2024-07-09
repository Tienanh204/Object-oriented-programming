#include"main.h"

bool WrongPassword()
{
	cout << "Create your password: ";
	string pass;
	getline(cin, pass);
	system("cls");
	cout << "Password created successfully." << endl;
	cout << "-------------- LOG IN --------------" << endl;
	int i = 3;
	while (i > 0)
	{
		i--;
		cout << "Enter password: ";
		string passWord;
		getline(cin, passWord);
		if (passWord == pass)
		{
			system("cls");
			cout << "Log in successfully!" << endl;
			return true;
		}
		else
		{
			cout << "Incorrect password, you have " << i << " attempts left." << endl;
		}
	}
	return false;
}

int main()
{
	if (WrongPassword())
	{
		cout << "*************** WELLCOME MY WEBSITE ********************" << endl;
		cout << "Name: Truong Tien Anh" << endl;
		cout << "MSSV: 22120017" << endl;
		cout << "Class: 22CTT2" << endl;
	}
	else
	{
		cout << "Login failed" << endl;
	}
	return 0;
}