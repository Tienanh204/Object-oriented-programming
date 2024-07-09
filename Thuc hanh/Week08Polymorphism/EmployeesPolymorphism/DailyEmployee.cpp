#include "DailyEmployee.h"

DailyEmployee::DailyEmployee() {
	_dayCount = 0;
	_paymentPerDay = 0;
}
DailyEmployee::DailyEmployee(int dayCount, int paymentPerDay) {
	_dayCount = dayCount;
	_paymentPerDay = paymentPerDay;
}
int DailyEmployee::getDayCount() const {
	return _dayCount;
}

int DailyEmployee::getPaymentPerDay() const {
	return _paymentPerDay;
}

void DailyEmployee::setDayCount(int dayCount) {
	_dayCount = dayCount;
}

void DailyEmployee::setPaymentPerDay(int paymentPerDay) {
	_paymentPerDay = paymentPerDay;
}

int DailyEmployee::salary()  {
	return _dayCount * _paymentPerDay;
}

std::string DailyEmployee::toString()  {
	return "Daily employee";
}