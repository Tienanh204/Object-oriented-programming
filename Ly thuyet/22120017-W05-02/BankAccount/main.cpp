#include <iostream>
#include "BankAccount.h"

int main() {
    // increate account
    SavingAccount savings("22120017", "Truong Tien Anh", 150000, 3.1, 6, 0);

    // set months deposite
   // savings.setMonDeposite(7);//months deposite = current + moths
    // Deposit
    savings.deposit(5000);
    savings.viewBalance();

    // Withdraw
    savings.setMonDeposite(7);
    savings.withdraw(2000);
    savings.viewBalance();

    // view account balance
    savings.viewBalance();

    return 0;
}
