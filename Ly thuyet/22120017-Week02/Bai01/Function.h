#include<iostream>
#include <string>
#include<sstream>
#include<tuple>
#include<fstream>
#include <ctime>
#include <utility>
#include<algorithm>
#include<vector>
using namespace std;

class DateTime
{
private:
	int Year, Month, Day;
	int Hour, Minute, Second;
public:
	DateTime() : Year(0), Month(0), Day(0), Hour(0), Minute(0), Second(0) {}
	DateTime(int Year, int Month, int Day, int Hour, int Minute, int Second) {
		this->Year = Year;
		this->Month = Month;
		this->Day = Day;
		this->Hour = Hour;
		this->Minute = Minute;
		this->Second = Second;
	}
	int getYear() { return Year; }
	int getMonth() { return Month; }
	int getDay() { return Day; }
	int getHour() { return Hour; }
	int getMinute() { return Minute; }
	int getSecond() { return Second; }
};

class Book
{
private:
	string ISBN, Title, Author, Language;
	int publishedYear, stockLevel;
	float Price;
	DateTime inputDate;
public:
	Book() : ISBN(""), Title(""), Author(""), Language(""), publishedYear(0), Price(0.0f), stockLevel(0) {};
	Book(string ISBN, string Title, string Author, string Language,
		int publishedYear, float Price, int stockLevel,
		DateTime inputDate = DateTime())
	{
		this->ISBN = ISBN;
		this->Title = Title;
		this->Author = Author;
		this->Language = Language;
		this->publishedYear = publishedYear;
		this->Price = Price;
		this->stockLevel = stockLevel;
		this->inputDate = inputDate;
	}
	string getISBN() { return ISBN; }
	string getTitle() { return Title; }
	string getAuthor() { return Author; }
	string getLanguage() { return Language; }
	int getPublishedYear() { return publishedYear; }
	float getPrice() { return Price; }
	DateTime getInputDate() { return inputDate; }
	int getStockLevel() { return stockLevel; };

	void setStockLevel(int newStockLevel) { stockLevel = newStockLevel; };
	void setInputDate(int Year, int Month, int Day, int Hour, int Minute, int Second)
	{
		DateTime(Year, Month, Day, Hour,
			Minute, Second);
	}
};

class BookStore
{
private:
	string Name;
	vector<Book> Data;
public:
	BookStore();
	BookStore(string Name) { Name = Name; };
	void loadData();
	int getSize() { return Data.size();  };

	void sortByPrice();
	void displayTopKa(int k);
	void inputBook();
	void addBookToCart(string ISBN);
	pair<bool, int> checkListBook(string ISBN);
	//Them sach vao gio hang
	vector<Book> bookInCart;
	//Don hang duoc ban
	void createOrder();
	void displayLowStock();
};

int luachon();
bool cmpPriceThenName(Book a, Book b);
bool cmpInputDate(Book a, Book b);
void displayBookInCart(vector<Book> bookInCart);
bool checkBookInCart(vector<Book>bookInCart, string ISBN);
string getCurrentDateTime();
void displayAllBook(vector<Book> Data, string nameBook);
void writeFileText(vector<Book> book);
void writeFileText(vector<tuple<string, Book, string>> book);
void displayOrders(vector<tuple<string, Book, string>> book);