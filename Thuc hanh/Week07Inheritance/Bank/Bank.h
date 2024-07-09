#pragma once
#include <iostream>
#include <vector>
#include<string>
using namespace std;

class BankAccount {
private:
    std::string _name;
    int _balance;
public:
    std::string name() const { return _name; }
    BankAccount() { _name = ""; _balance = 0; }
    BankAccount(std::string name, int balance) :
        _name(name), _balance(balance) {}

    int withdraw(int amount);
    //Setter
    void setName(string name);
    void setBalance(int balance);
    //Getter
    string getName();
    int getBalance();
};

class BankAccountV2 : public BankAccount {
public:
    BankAccountV2(string name, int balance) :BankAccount(name, balance) {};
    int withdraw(int amount);
};


inline auto getAllAccountsV2() {
    return std::vector<BankAccountV2> {
        BankAccountV2("Alice", 60000),
            BankAccountV2("Bob", 100000),
            BankAccountV2("Charlie", 100000),
            BankAccountV2("David", 200000),
            BankAccountV2("Eve", 300000),
    };
}

inline auto getAllAccounts() {
    return std::vector<BankAccount> {
        BankAccount("Alice", 60000),
            BankAccount("Bob", 100000),
            BankAccount("Charlie", 100000),
            BankAccount("David", 200000),
            BankAccount("Eve", 300000),
    };
}