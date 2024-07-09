#include "Manager.h"

Manager::Manager() {
	_employeeCount = 0;
	_paymentPerEmployee = 0;
	_baseSalary = 0;
}
Manager::Manager(int employeeCount, int paymentPerEmployee, int baseSalary) {
	_employeeCount = employeeCount;
	_paymentPerEmployee = paymentPerEmployee;
	_baseSalary = baseSalary;
}
int Manager::getEmployeeCount() const {
	return _employeeCount;
}

int Manager::getPaymentPerEmployee() const {
	return _paymentPerEmployee;
}

int Manager::getBaseSalary() const {
	return _baseSalary;
}

void Manager::setEmployeeCount(int employeeCount) {
	_employeeCount = employeeCount;
}

void Manager::setPaymentPerEmployee(int paymentPerEmployee) {
	_paymentPerEmployee = paymentPerEmployee;
}

void Manager::setBaseSalary(int baseSalary) {
	_baseSalary = baseSalary;
}

int Manager::salary()  {
	return _baseSalary + _employeeCount * _paymentPerEmployee;
}

std::string Manager::toString()  {
	return "Manager";
}