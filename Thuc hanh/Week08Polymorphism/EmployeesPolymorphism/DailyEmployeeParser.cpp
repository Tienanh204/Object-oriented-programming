#include "DailyEmployeeParser.h"

std::string DailyEmployeeParser::toString()  {
	return "DailyEmployee";
}
Object* DailyEmployeeParser::parse(std::string input)  {
	Object* reOject = nullptr;
	std::stringstream ss(input);
	std::string obj1, obj2;
	int dayCount = 0, paymentPerPay = 0;
	getline(ss, obj1, ',');
	getline(ss, obj2);

	int splitPosition;
	splitPosition = obj1.find_first_of('=');
	dayCount = stoi(obj1.substr(splitPosition + 1));

	splitPosition = obj2.find_first_of('=');
	paymentPerPay = stoi(obj2.substr(splitPosition + 1));

	reOject = new DailyEmployee(dayCount, paymentPerPay);

	return reOject;
}
std::string DailyEmployeeParser::parsedObjectName() {
	return "DailyEmployee";
}