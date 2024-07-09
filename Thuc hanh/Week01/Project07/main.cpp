#include"main.h"

void Menu() {
    int choice = 1;
    char key;
    while (true) {
        system("cls");
        cout << "*************** MENU ****************" << endl;
        cout << "1. Categories" << endl;
        cout << "2. Products" << endl;
        cout << "3. Orders" << endl;
        cout << "4. Report" << endl;
        cout << "5. Quit" << endl;
        cout << "*************************************" << endl;

        switch (choice)
        {
        case 1:
            cout << "\n=> Categories" << endl;
            break;
        case 2:
            cout << "\n=> Products" << endl;
            break;
        case 3:
            cout << "\n=> Orders" << endl;
            break;
        case 4:
            cout << "\n=> Report" << endl;
            break;
        case 5:
            cout << "\n=> Quit" << endl;
            break;
        }

        key = _getch();

        if (key == 72) 
        { 
            if (choice == 1)
                choice = 5;
            else
                choice -= 1;
        }
        else if (key == 80) 
        { 
            if (choice == 5)
                choice = 1;
            else
                choice += 1;
        }
        else if (key == 13) 
        { // Enter

            switch (choice)
            {
            case 1:
                cout << "\nYour selection is Categories." << endl;
                // Code
                break;
            case 2:
                cout << "\nYour selection is Products." << endl;
                // Code
                break;
            case 3:
                cout << "\nYour selection is Orders." << endl;
                // Code
                break;
            case 4:
                cout << "\nYour selection is Report." << endl;
                // Code
                break;
            case 5:
                cout << "\nYou are log out" << endl;
                return;
            }
            cout << "\nPress space to continue!";
            _getch();
        }
        else if (key == 27)
        { //ESC
            cout << "\nYou chose to return to the menu." << endl;
            cout << "\nPress any key to continue...";
            _getch();
        }
    }
}
int main()
{
    Menu();
}