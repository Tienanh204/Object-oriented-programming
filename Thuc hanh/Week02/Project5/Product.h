#include<iostream>
#include<string>
using namespace std;

class Date
{
private:
    int day, month, year;

public:
    Date() { day = 0; month = 0; year = 0; };
    Date(int d, int m, int y)
    {
        day = d;
        month = m;
        year = y;
    }

    int getDay() { return day; };
    int getMonth() { return month; };
    int getYear() { return year; };

    void setDay(int d) { day = d; };
    void setMonth(int m) { month = m; };
    void setYear(int y) { year = y; };
};

class ProductInput
{
private:
    string ID, Name;
    float Price;
    Date ExDate;

public:
    ProductInput()
    {
        ID = "";
        Name = "";
        Price = 0;
        ExDate = Date();
    }

    string getID();
    string getName();
    float getPrice();
    Date getExDate();

    void setID(string val);
    void setName(string val);
    void setPrice(float val);
    void setExDate(int d, int m, int y) { ExDate = Date(d, m, y); }

    void input();
    void output();
};
