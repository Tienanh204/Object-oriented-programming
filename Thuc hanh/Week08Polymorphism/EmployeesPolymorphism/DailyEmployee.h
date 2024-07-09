#pragma once
#include"Employee.h"
class DailyEmployee : public Employee {
private:
	int _dayCount;
	int _paymentPerDay;
public:
	DailyEmployee();
	DailyEmployee(int dayCount, int paymentPerDay);
	int getDayCount() const;

	int getPaymentPerDay() const;

	void setDayCount(int dayCount);

	void setPaymentPerDay(int paymentPerDay);

	int salary() override;

	std::string toString() override;
};