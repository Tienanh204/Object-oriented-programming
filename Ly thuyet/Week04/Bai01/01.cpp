#include<iostream>
#include<string>
using namespace std;
class Mystring
{
private:
    char* pString;
public:
    Mystring();
    Mystring(const char * other);
    ~Mystring();
    void input();

    bool operator == (const Mystring &another) const;
    Mystring& operator+=(const Mystring& other);
    Mystring& operator=(const Mystring& other);
    friend ostream& operator << (ostream& out, const Mystring& a);
};

Mystring::Mystring()
{
    pString = new char[1];
    *pString = '\0';
}

Mystring :: Mystring(const char* other)
{
    int length = strlen(other);
    pString = new char[length + 1];
    for (int i = 0; i < length; i++)
    {
        pString[i] = other[i];
    }
}

Mystring::~Mystring()
{
    delete[] pString;
}

bool Mystring::operator ==(const Mystring& other) const 
{
    return strcmp(pString, other.pString) == 0;
}

Mystring& Mystring::operator+=(const Mystring& other)
{
    int length1 = strlen(pString);
    int length2 = strlen(other.pString);

    char* temp = new char[length1 + length2 + 1];
    for (int i = 0; i < length1; i++)
    {
        temp[i] = pString[i];
    }
    for (int i = 0; i < length2; i++)
    {
        temp[length1 + i] = other.pString[i];
    }
    temp[length1 + length2] = '\0';
    delete[] pString;
    pString = temp;
    return *this;
}

Mystring& Mystring::operator=(const Mystring& other)
{
    if (this != &other)
    {
        if (pString != NULL)
        {
            delete[] pString;
        }
        int length = strlen(other.pString);
        pString = new char[length + 1];
        for (int i = 0; i < length; i++)
        {
            pString[i] = other.pString[i];
        }
        pString[length] = '\0';
    }
    return *this;
}

ostream& operator<<(ostream& out, const Mystring& a)
{
    int length = strlen(a.pString);
    for (int i = 0; i < length; i++)
    {
        out << a.pString[i];
    }
    return out;
}

void Mystring::input()
{
    char* buffer = new char[1000];
    cin.getline(buffer, 1000);

    delete[] pString;
    pString = new char[strlen(buffer) + 1];
    strcpy_s(pString, strlen(buffer) + 1, buffer);
}

int main()
{
    Mystring a, b;
    cout << "Chuoi A: "; a.input();
    cout << "Chuoi B: "; b.input();

    cout << "Cau a" << endl;
    if (a == b)
    {
        cout << "Chuoi A bang chuoi B" << endl;
    }
    else
    {
        cout << "Chuoi A khac chuoi B" << endl;
    }
    
    cout << "Cau b" << endl;
    cout << "Ket qua cua A += B: ";
    a += b;
    cout << a << endl;

    cout << "Cau c" << endl;
    cout << "Ket qua cua A = B: ";
    a = b;
    cout << a << endl;
}
