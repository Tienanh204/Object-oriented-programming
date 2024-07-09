#include "Student.h"
#include "StudentList.h"

int MENU1();
int MENU2();
int MENU3();

int main() {
	StudentList student;
	student.readFromCSV("Text.csv");
	while ((true))
	{
		int choice = MENU1();
		bool replacement;
		if (choice == 1)
		{
			while (true)
			{
				choice = MENU2();
				if (choice == 1)
				{
					replacement = true;
				}
				else if (choice == 2)
				{
					replacement = false;
				}
				else if (choice == 0)
				{
					break;
				}
				while (true)
				{
					choice = MENU3();
					if (choice == 1)
					{
						student.randomStudentSource(replacement);
						if (replacement = true)
						{
							if (student.getStudent().empty())
							{
								cout << "All the students got to speak! End of class!" << endl;
								system("cls");
								student.updateFileCSV("Text.csv");
								return 0;
							}
						}
						system("pause");
					}
					else if (choice == 0)
					{
						break;
					}
					system("cls");
				}
				system("cls");
			}
		}
		//-----------------------------------------
		else if (choice == 2)
		{
			student.calculateProbability("config.txt");
			while (true)
			{
				choice = MENU2();
				if (choice == 1)
				{
					replacement = true;
				}
				else if (choice == 2)
				{
					replacement = false;

				}
				else if (choice == 0)
				{
					break;
				}
				while (true)
				{
					choice = MENU3();
					if (choice == 1)
					{
						student.randomStudentConfig(replacement);
						if (replacement = true)
						{
							if (student.getStudent().empty())
							{
								cout << "All the students got to speak! End of class!" << endl;
								system("cls");
								student.updateFileCSV("Text.csv");
								return 0;
							}
						}
						system("pause");
					}
					else if (choice == 0)
					{
						break;
					}
					system("cls");
				}
				system("cls");
			}
		}
		//----------------------------------------
		else if (choice == 0)
		{
			cout << "------------------------------" << endl;
			cout << "|    THANK YOU FOR USING     |" << endl;
			cout << "------------------------------" << endl;
			student.updateFileCSV("Text.csv");
			system("pause");
			return 0;
		}
		system("cls");
	}
}

int MENU1()
{
	system("cls");
	cout << "************************ MENU ************************" << endl << endl;
	cout << "1. Calculate the ratio according to Source code" << endl << endl;
	cout << "2. Calculate the ratio according to file config.csv" << endl << endl;
	cout << "0. Exit!" << endl << endl;
	cout << "******************************************************" << endl;
	cout << "Enter your choice: ";
	int choice; cin >> choice;
	system("cls");
	return choice;
}

int MENU2()
{
	system("cls");
	cout << "************************ MENU ************************" << endl << endl;
	cout << "1. Select random students with replacement." << endl << endl;
	cout << "2. Select random students without replacement." << endl << endl;
	cout << "0. Exit!" << endl << endl;
	cout << "******************************************************" << endl;
	cout << "Enter your choice: ";
	int choice; cin >> choice;
	system("cls");
	return choice;
}

int MENU3()
{
	system("cls");
	cout << "************************ RANDOM ************************" << endl << endl;
	cout << "1. Select random students" << endl << endl;
	cout << "0. Exit!" << endl << endl;
	cout << "******************************************************" << endl;
	cout << "Enter your choice: ";
	int choice; cin >> choice;
	system("cls");
	return choice;
}