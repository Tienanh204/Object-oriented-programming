#pragma once
#include"Employee.h"

class Manager : public Employee {
private:
	int _employeeCount;
	int _paymentPerEmployee;
	int _baseSalary;
public:
	Manager();
	Manager(int employeeCount, int paymentPerEmployee, int baseSalary);
	int getEmployeeCount() const;

	int getPaymentPerEmployee() const;

	int getBaseSalary() const;
	void setEmployeeCount(int employeeCount);

	void setPaymentPerEmployee(int paymentPerEmployee);

	void setBaseSalary(int baseSalary);

	int salary() override;
	std::string toString() override;
};

