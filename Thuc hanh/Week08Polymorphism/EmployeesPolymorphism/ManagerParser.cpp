#include "ManagerParser.h"
std::string ManagerParser::toString()  {
	return "Manager";
}

std::string ManagerParser::parsedObjectName()  {
	return "Manager";
}
Object* ManagerParser::parse(std::string input)  {
	Object* reOject = nullptr;
	std::stringstream ss(input);
	std::string obj1, obj2, obj3;
	int employeeCount = 0, paymentPerEmployee = 0, baseSalary = 0;
	getline(ss, obj1, ',');
	getline(ss, obj2, ',');
	getline(ss, obj3);

	int splitPosition;
	splitPosition = obj1.find_first_of('=');
	employeeCount = stoi(obj1.substr(splitPosition + 1));

	splitPosition = obj2.find_first_of('=');
	paymentPerEmployee = stoi(obj2.substr(splitPosition + 1));

	splitPosition = obj3.find_first_of('=');
	baseSalary = stoi(obj3.substr(splitPosition + 1));

	reOject = new Manager(employeeCount, paymentPerEmployee, baseSalary);

	return reOject;
}