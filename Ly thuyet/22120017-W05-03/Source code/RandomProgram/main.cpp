#include"RandomProgram.h"
int MENU()
{
    system("cls");
    cout << "==============================" << endl;
    cout << "            MENU              " << endl;
    cout << "==============================" << endl;
    cout << "1. Random" << endl;
    cout << "2. Exit!" << endl;
    cout << "==============================" << endl;
    cout << "Choice: ";

    int choice;
    cin >> choice;
    return choice;
    system("cls");
}
int main()
{
    Session session;
    session.readFromCSV("Students");
    while (true)
    {
        int Choice = MENU();

        if (Choice == 1)
        {
            session.calculateProbability("config");
            cout << session.chooseRandomStudent() << endl;
            system("pause");
        }
        else if (Choice == 2)
        {
            cout << "Cam on ban da su dung chuong trinh!" << endl;
            session.updateFileCSV("Students");
            break;
            system("pause");
        }
        else
        {
            cout << "Lua chon khong hop le. Vui long chon lai!" << endl;
            system("pause");
        }
        system("cls");
    }
    return 0;
}

