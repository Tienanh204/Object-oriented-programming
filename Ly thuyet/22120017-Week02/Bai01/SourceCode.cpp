#include "Function.h"

void BookStore::loadData()
{
	ifstream fin;
	fin.open("book.txt", ios::in);
	if (!fin)
	{
		cout << "Can't open file" << endl;
		return;
	}
	string temp = "";

	while (getline(fin, temp))
	{
		if (temp.empty())
			continue;
		//cout << temp << endl;
		string ISBN, Title, Author, Language;
		string publishedYear, stockLevel, Price;
		string Year, Month, Day, Hour, Minute, Second;
		string date, time;

		stringstream ss(temp);
		getline(ss, ISBN, ',');
		getline(ss, Title, ',');
		getline(ss, Author, ',');
		getline(ss, Language, ',');
		getline(ss, publishedYear, ',');
		getline(ss, Price, ',');
		getline(ss, stockLevel, ',');
		getline(ss, date, '-');
		getline(ss, time, ' ');

		stringstream ssDate(date);
		getline(ssDate, Day, '/');
		getline(ssDate, Month, '/');
		getline(ssDate, Year);

		stringstream ssTime(time);
		getline(ssTime, Hour, ':');
		getline(ssTime, Minute, ':');
		getline(ssTime, Second);

		Book book(ISBN, Title, Author, Language,
			stoi(publishedYear), stof(Price),
			stoi(stockLevel), DateTime(stoi(Year),
				stoi(Month), stoi(Day), stoi(Hour),
				stoi(Minute), stoi(Second)));
		Data.push_back(book);
	}
	fin.close();
}

//Cau1
bool cmpPriceThenName(Book a, Book b)
{
	if (a.getPrice() != b.getPrice())
		return a.getPrice() < b.getPrice();
	return a.getTitle() < b.getTitle();
}
void BookStore::sortByPrice()
{
	sort(Data.begin(), Data.end(), cmpPriceThenName);
	displayAllBook(Data, Name);
}

void displayAllBook(vector<Book> Data, string nameBook)
{
	cout << "<>*<>*<>*<>*<>*<>*<>*<>*<>*<>*<>*<>*<>*<>*<>*<>*<>" << endl;
	cout << "|                 DANH SACH SACH                 | " << endl;
	cout << "<>*<>*<>*<>*<>*<>*<>*<>*<>*<>*<>*<>*<>*<>*<>*<>*<>" << endl;
	cout << "BOOK IS NAME: TIEM SACH TRGTANHH" << nameBook << endl;
	cout << "--------------------------------------------------" << endl;
	for (int i = 0; i < Data.size(); i++)
	{
		cout << "ISBN: " << Data[i].getISBN() << endl;
		cout << "Title: " << Data[i].getTitle() << endl;
		cout << "Author: " << Data[i].getAuthor() << endl;
		cout << "Language: " << Data[i].getLanguage() << endl;
		cout << "Published Year: " << Data[i].getPublishedYear() << endl;
		cout << "Price: " << Data[i].getPrice() << endl;
		cout << "Stock level: " << Data[i].getStockLevel() << endl;
		cout << "Input date: " << Data[i].getInputDate().getDay() << "/"
			<< Data[i].getInputDate().getMonth() << "/"
			<< Data[i].getInputDate().getYear() << "-"
			<< Data[i].getInputDate().getHour() << ":"
			<< Data[i].getInputDate().getMinute() << ":"
			<< Data[i].getInputDate().getSecond() << endl;
		cout << "--------------------------------------------------" << endl;
	}
}

//Cau2
bool cmpInputDate(Book a, Book b)
{
	string dateA = to_string(a.getInputDate().getYear())
		+ "/" + to_string(a.getInputDate().getMonth())
		+ "/" + to_string(a.getInputDate().getDay());

	string dateB = to_string(b.getInputDate().getYear())
		+ "/" + to_string(b.getInputDate().getMonth())
		+ "/" + to_string(b.getInputDate().getDay());

	string timeA = to_string(a.getInputDate().getHour())
		+ ":" + to_string(a.getInputDate().getMinute())
		+ ":" + to_string(a.getInputDate().getSecond());

	string timeB = to_string(b.getInputDate().getHour())
		+ ":" + to_string(b.getInputDate().getMinute())
		+ ":" + to_string(b.getInputDate().getSecond());

	if (dateA != dateB)
		return dateA > dateB;
	return timeA > timeB;
}
void BookStore::displayTopKa(int k)
{
	sort(Data.begin(), Data.end(), cmpInputDate);
	cout << "***************** DANH SACH TOP "<<k<<" *****************" << endl;
	for (int i = 0; i < k; i++)
	{
		cout << "ISBN: " << Data[i].getISBN() << endl;
		cout << "Title: " << Data[i].getTitle() << endl;
		cout << "Author: " << Data[i].getAuthor() << endl;
		cout << "Language: " << Data[i].getLanguage() << endl;
		cout << "Published Year: " << Data[i].getPublishedYear() << endl;
		cout << "Price: " << Data[i].getPrice() << endl;
		cout << "Stock level: " << Data[i].getStockLevel() << endl;
		cout << "Input date: " << Data[i].getInputDate().getDay() << "/"
			<< Data[i].getInputDate().getMonth() << "/"
			<< Data[i].getInputDate().getYear() << "-"
			<< Data[i].getInputDate().getHour() << ":"
			<< Data[i].getInputDate().getMinute() << ":"
			<< Data[i].getInputDate().getSecond() << endl;
		cout << "---------------------------------------------------" << endl;
	}
}

//Cau3
//ham kiem tra 1 cuon sach va tra ve vi tri cua no
pair<bool, int>BookStore::checkListBook(string ISBN)
{
	bool check = false;
	int index = -1;
	for (int i = 0; i < Data.size(); i++)
	{
		if (Data[i].getISBN() == ISBN)
		{
			check = true;
			index = i;
			break;
		}
	}
	return { check,index };
}
void BookStore::inputBook()
{
	Book book;
	string ISBN, Title, Author, Language;
	int publishedYear, stockLevel;
	int Year, Month, Day, Hour, Minute, Second;
	float Price;
	cout << "--------------------- THONG TIN SACH MOI -------------------" << endl;
	cin.ignore();
	cout << "ISBN: "; getline(cin, ISBN);
	cout << "Title: "; getline(cin, Title);
	cout << "Author: "; getline(cin, Author);
	cout << "Language: "; getline(cin, Language);
	cout << "Published Year: "; cin >> publishedYear;
	cout << "Price: "; cin >> Price;
	cout << "Stock Level: "; cin >> stockLevel;
	cout << "Day Month Year: "; cin >> Day >> Month >> Year;
	cout << "Hour Minute Second: "; cin >> Hour >> Minute >> Second;
	cout << "------------------------------------------------------------" << endl;

	pair<bool, int> checkBook = checkListBook(ISBN);
	if (checkBook.first)
	{
		int newStockLevel = Data[checkBook.second].getStockLevel();
		cout << "Sach da ton tai" << endl;
		Data[checkBook.second].setStockLevel(newStockLevel);
		Data[checkBook.second].setInputDate(Year,
			Month, Day, Hour, Minute, Second);
	}
	else
	{
		cout << "Sach da duoc them" << endl;
		Book book(ISBN, Title, Author,
			Language, publishedYear, Price,
			stockLevel, DateTime(Year, Month,
				Day, Hour, Minute, Second));
		Data.push_back(book);
	}
}
//Cau4
void displayBookInCart(vector<Book> bookInCart)
{
	cout << "--------------------- GIO HANG -------------------" << endl;
	if (!bookInCart.empty())
	{
		for (int i = 0; i < bookInCart.size(); i++)
		{
			cout << "ISBN: " << bookInCart[i].getISBN() << endl;
			cout << "Title: " << bookInCart[i].getTitle() << endl;
			cout << "Author: " << bookInCart[i].getAuthor() << endl;
			cout << "Language: " << bookInCart[i].getLanguage() << endl;
			cout << "Published Year: " << bookInCart[i].getPublishedYear() << endl;
			cout << "Price: " << bookInCart[i].getPrice() << endl;
			cout << "Stock level: " << bookInCart[i].getStockLevel() << endl;
			cout << "Input date: " << bookInCart[i].getInputDate().getDay() << "/"
				<< bookInCart[i].getInputDate().getMonth() << "/"
				<< bookInCart[i].getInputDate().getYear() << "-"
				<< bookInCart[i].getInputDate().getHour() << ":"
				<< bookInCart[i].getInputDate().getMinute() << ":"
				<< bookInCart[i].getInputDate().getSecond() << endl;
			cout << "--------------------------------------------------" << endl;
		}
	}
	else
	{
		cout << "Gio hang rong!" << endl;
		return;
	}
}

bool checkBookInCart(vector<Book>bookInCart, string ISBN)
{
	for (int i = 0; i < bookInCart.size(); i++)
	{
		if (bookInCart[i].getISBN() == ISBN)
		{
			return true;
		}
	}
	return false;
}

void BookStore::addBookToCart(string ISBN)
{
	pair<bool, int> checkBook = checkListBook(ISBN);
	bool checkCart = checkBookInCart(bookInCart, ISBN);
	if (checkCart)
	{
		cout << "Sach da co trong gio hang!" << endl;
		return;
	}
	int newStockLevel = Data[checkBook.second].getStockLevel();
	if (checkBook.first && newStockLevel > 0)
	{
		newStockLevel--;
		Data[checkBook.second].setStockLevel(newStockLevel);
		bookInCart.push_back(Data[checkBook.second]);

		if (newStockLevel == 0)//Neu sach het thi xoa sach
		{
			Data.erase(Data.begin() + checkBook.second);
		}
		cout << "Sach duoc them vao gio hang!" << endl << endl;
		displayBookInCart(bookInCart);
	}
	else
	{
		cout << "Sach khong ton tai trong gio hang!" << endl;
		return;
	}
}

//Cau5
vector<tuple<string, Book, string >> Orderd;
void writeFileText(vector<tuple<string, Book, string>> Orderd)
{
	ofstream fout;
	fout.open("Order.txt", ios::out);
	if (!fout)
	{
		cout << "Can't open file" << endl;
		return;
	}
	for (int i = Orderd.size() - 1; i >= 0; i--)
	{
		string nameCustomer = get<0>(Orderd[i]);
		Book bookInfo = get<1>(Orderd[i]);
		string timeShopping = get<2>(Orderd[i]);

		fout << nameCustomer << "," << bookInfo.getISBN() << "," << bookInfo.getTitle() << "," << bookInfo.getAuthor() << "," << bookInfo.getLanguage() << ","
			<< bookInfo.getPublishedYear() << "," << bookInfo.getPrice() << "," << bookInfo.getStockLevel() << ","
			<< timeShopping << endl;
	}
	fout.close();
}
//Ham lay thoi gian tai thoi diem mua hang
string getCurrentDateTime()
{
	time_t now = time(0);
	struct tm localTimeInfo;

	if (localtime_s(&localTimeInfo, &now) != 0)
	{
		cout << "Error: Failed to get local time." << endl;
		return "";
	}

	char buffer[80];
	strftime(buffer, 80, "%d/%m/%Y-%H:%M:%S", &localTimeInfo);
	return string(buffer);
}

void displayOrders(vector<tuple<string, Book, string>> book)
{
	cout << "<>*<>*<>*<>*<>*<>*<>*<>*<>*<>*<>*<>*<>*<>*<>*<>*<>" << endl;
	cout << "|                     DON HANG                   | " << endl;
	cout << "<>*<>*<>*<>*<>*<>*<>*<>*<>*<>*<>*<>*<>*<>*<>*<>*<>" << endl;
	for (int i = book.size() - 1; i >= 0; i--)
	{
		string nameCustomer = get<0>(book[i]);
		Book bookInfo = get<1>(book[i]);
		string timeShopping = get<2>(book[i]);

		cout << "> Khach hang: " << nameCustomer << endl;
		cout << "> Thong tin sach" << endl;

		cout << "  +ISBN: " << bookInfo.getISBN() << endl;
		cout << "  +Title: " << bookInfo.getTitle() << endl;
		cout << "  +Author: " << bookInfo.getAuthor() << endl;
		cout << "  +Language: " << bookInfo.getLanguage() << endl;
		cout << "  +Published Year: " << bookInfo.getPublishedYear() << endl;
		cout << "  +Price: " << bookInfo.getPrice() << endl;
		cout << "  +Stock level: " << bookInfo.getStockLevel() << endl;
		cout << "  +Input date: " << bookInfo.getInputDate().getDay() << "/"
			<< bookInfo.getInputDate().getMonth() << "/"
			<< bookInfo.getInputDate().getYear() << "-"
			<< bookInfo.getInputDate().getHour() << ":"
			<< bookInfo.getInputDate().getMinute() << ":"
			<< bookInfo.getInputDate().getSecond() << endl;

		cout << "> Thoi thanh toan: " << timeShopping << endl;
		cout << "---------------------------------------------------" << endl;
	}
}

void BookStore::createOrder()
{
	displayBookInCart(bookInCart);
	cin.ignore();
	cout << endl << endl;
	cout << "Nhap ISBN de thuc hien thanh toan: ";
	string ISBN; getline(cin, ISBN);

	int indexBook = -1;
	if (checkBookInCart(bookInCart, ISBN))
	{
		for (int i = 0; i < bookInCart.size(); i++)
		{
			if (bookInCart[i].getISBN() == ISBN)
			{
				indexBook = i;
				break;
			}
		}
		cout << "Ten khach hang: ";
		string nameCustomer; getline(cin, nameCustomer);

		cout << "Thoi thanh toan: ";
		string timeShopping = getCurrentDateTime();
		cout << timeShopping << endl << endl;

		Orderd.push_back({ nameCustomer, bookInCart[indexBook],timeShopping });
		displayOrders(Orderd);
		writeFileText(Orderd);
		bookInCart.erase(bookInCart.begin() + indexBook);
	}
	else
	{
		cout << "ISBN khong hop le. Hay thu lai!" << endl;
		return;
	}
}

//Cau 6
void BookStore::displayLowStock()
{
	cout << "-------------- DANH SACH SACH SAP HET HANG -----------" << endl;
	bool check = false;
	for (int i = 0; i < Data.size(); i++)
	{
		if (Data[i].getStockLevel() < 50)
		{
			cout << "ISBN: " << Data[i].getISBN() << endl;
			cout << "Title: " << Data[i].getTitle() << endl;
			cout << "Author: " << Data[i].getAuthor() << endl;
			cout << "Language: " << Data[i].getLanguage() << endl;
			cout << "Published Year: " << Data[i].getPublishedYear() << endl;
			cout << "Price: " << Data[i].getPrice() << endl;
			cout << "Stock level: " << Data[i].getStockLevel() << endl;
			cout << "Input date: " << Data[i].getInputDate().getDay() << "/"
				<< Data[i].getInputDate().getMonth() << "/"
				<< Data[i].getInputDate().getYear() << "-"
				<< Data[i].getInputDate().getHour() << ":"
				<< Data[i].getInputDate().getMinute() << ":"
				<< Data[i].getInputDate().getSecond() << endl;
			cout << "---------------------------------------------------" << endl;
			check = true;
		}
	}
	if (!check)
	{
		cout << "Khong co sach nao sap het hang" << endl;
	}
}