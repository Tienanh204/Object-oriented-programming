#include"Function.h"

int main()
{
	BookStore store("TIEM SACH TRGTANHH");
	store.loadData();

	int choice;
	int k;
	while (1)
	{
		choice = luachon();
		if (choice == 1)
		{
			store.sortByPrice();
			system("pause");
		}
		else if (choice == 2)
		{
			do
			{
				cout << "Nhap K: ";
				cin >> k;
				if (k > store.getSize())
				{
					cout << "Nhap lai k < "
						<< store.getSize() << endl;
				}
			} while (k > store.getSize());
			store.displayTopKa(k);
			system("pause");
		}
		else if (choice == 3)
		{
			store.inputBook();
			system("pause");
		}
		else if (choice == 4)
		{
			cin.ignore();
			cout << "Nhap ISBN: ";
			string ISBN; getline(cin, ISBN);
			store.addBookToCart(ISBN);
			system("pause");
		}
		else if (choice == 5)
		{
			store.createOrder();
			system("pause");
		}
		else if (choice == 6)
		{
			store.displayLowStock();
			system("pause");
		}
		else if (choice == 0)
		{
			return 0;
		}
		system("cls");
	}
}

int luachon()
{
	system("cls");
	cout << "**************************************************************************************\n";
	cout << "|                                       MENU                                         |\n";
	cout << "**************************************************************************************\n";
	cout << "1. Xem danh sach sap xep theo gia ban tu thap den cao. Neu trung thi sap xep theo ten.\n";
	cout << "2. Xem danh sach top Ka sach moi nhat.\n";
	cout << "3. Nhap sach neu sach chua co thi them vao danh sach. Neu co thi xu ly yeu cau.\n";
	cout << "4. Them sach vao gio hang. Nguoi ban se nhap ISBN.\n";
	cout << "5. Thanh toan. Tao don hang.\n";
	cout << "6. Xem danh sach cac sach xap het hang.\n";
	cout << "0. Thoat !\n";
	cout << "**************************************************************************************\n";
	cout << "Nhap lua chon : ";

	int choice;
	cin >> choice;

	system("cls");
	return choice;
}