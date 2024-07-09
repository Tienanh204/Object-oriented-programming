#include"Bank.h"

int BankAccount::withdraw(int amount) {
    if (_balance >= amount) {
        _balance -= amount;
        return amount;
    }
    return 0;
}

//Setter
void BankAccount::setName(string name) {
    _name = name;
}
void BankAccount::setBalance(int balance) {
    _balance = balance;
}

//Getter
string BankAccount::getName() {
    return _name;
}
int BankAccount::getBalance() {
    return _balance;
}

int BankAccountV2::withdraw(int amount) {
    int newBanlance = getBalance() - amount;
    if (newBanlance >= 50000) {
        setBalance(newBanlance);
        return amount;
    }
    return 0;
}