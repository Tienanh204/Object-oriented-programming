#pragma once
#pragma once
#include<iostream>
#include<math.h>
#include<string>
#include<vector>
using namespace std;

class BankAccount
{
private:
	string ID;
	string ownerName;
	double balance;
public:
	BankAccount();
	BankAccount(string _ID,
		string _ownerName, double _balance);

	//Getter 
	string getID();
	string getName();
	double getBalance();

	//Setter
	void setID(string _id);
	void setName(string _ownerName);
	void setBalance(double _balance);

	//Process
	void deposit(double amount);
	void withdraw(double amount);
	void viewBalance();
};

class SavingAccount : public BankAccount
{
private:
	double interestRate;//Lai xuat
	int term;//Ki han (thang)
	int monDeposite;//So thang gu hien tai
public:
	SavingAccount();
	SavingAccount(string _ID, string _ownerName,
		double _balance, double _interestRate, int _term, int _monDeposite);
	
	//Getter
	double getInterestRate();
	int getTerm();
	int getMonDeposite();

	//Process
	double calculateInterest(int month);
	void setMonDeposite(int months);
	void deposit(double amount);
	void withdraw(double amount);
	void viewBalance();
	double resetAccount();
};
