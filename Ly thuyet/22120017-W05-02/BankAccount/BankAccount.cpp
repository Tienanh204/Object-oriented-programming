#include"BankAccount.h"


//--------------------- BankAccount ----------------------
//Ham bo tro
string BankAccount::getID()
{
	return ID;
}
string BankAccount::getName()
{
	return ownerName;
}
double BankAccount::getBalance()
{
	return balance;
}

void BankAccount::setID(string _id)
{
	ID = _id;
}
void BankAccount::setName(string _ownerName)
{
	ownerName = _ownerName;
}
void BankAccount::setBalance(double _balance)
{
	balance = _balance;
}

//Cau 1
BankAccount::BankAccount()
{
	balance = 0;
}

//Cau 2
BankAccount::BankAccount(string _id, string _name,
	double _accBalance)
{
	ID = _id;
	ownerName = _name;
	balance = _accBalance;
}


//Cau 3
void BankAccount::deposit(double amount)
{
	if (amount > 0)
	{
		balance += amount;
	}
	else
	{
		cout << "Invalid amount" << endl;
		return;
	}
}

//Cau 4
void BankAccount::withdraw(double amount)
{
	if (amount > 0)
	{
		if (amount <= balance)
		{
			balance -= amount;
		}
		else
		{
			cout << "Invalid amount" << endl;
			return;
		}
	}
	else
	{
		cout << "Invalid amount" << endl;
		return;
	}
}

//Cau 5
void BankAccount::viewBalance()
{
	cout << "Current balance: " << balance << endl;
}

//--------------------- SavingAccount ----------------------

//Ham bo tro
double SavingAccount::getInterestRate()
{
	return interestRate;
}

int SavingAccount::getTerm()
{
	return term;
}

int SavingAccount::getMonDeposite()
{
	return monDeposite;
}

double SavingAccount::calculateInterest(int months)
{
	return getBalance() * (interestRate / 100) * (months / 12.0);
}


//Cau 1
SavingAccount::SavingAccount() : BankAccount()
{
	interestRate = 0;
	monDeposite = 0;
}

//Cau 2
SavingAccount::SavingAccount(string _ID, string _ownerName, double _balance, double _interestRate, int _term, int _monDeposite)
	: BankAccount(_ID, _ownerName, _balance)
{
	interestRate = _interestRate;
	term = _term;
	monDeposite = _monDeposite;
}

//Cau 3
void SavingAccount::setMonDeposite(int months)
{
	if (months > monDeposite)
	{
		monDeposite += months;
	}
	else
	{
		cout << "Invalid months" << endl;
		return;
	}
}

//Cau 4
void SavingAccount::deposit(double amount)
{
	if (monDeposite >= term)
	{
		BankAccount::deposit(amount + calculateInterest(monDeposite));
		monDeposite = 0;
	}
	else
	{
		BankAccount::deposit(amount);
	}
}

//Cau 5
void SavingAccount::withdraw(double amount)
{
	if (monDeposite >= term)
	{
		BankAccount::withdraw(amount);
		BankAccount::deposit(calculateInterest(monDeposite));
		monDeposite = 0;
	}
	else
	{
		BankAccount::withdraw(amount);
	}
}

//Cau 6
void SavingAccount::viewBalance()
{
	cout <<"Account balance: "<< resetAccount() << endl;
}

//Cau 7
double SavingAccount::resetAccount()
{
	double amount = 0;
	if (monDeposite < term)
	{
		amount = getBalance();
	}
	else
	{
		BankAccount::deposit(calculateInterest(monDeposite));
		amount = getBalance();
	}
	monDeposite = 0;//month deposite = 0

	return amount;
}