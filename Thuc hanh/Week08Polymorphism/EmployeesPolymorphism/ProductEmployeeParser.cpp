#include "ProductEmployeeParser.h"

std::string ProductEmployeeParser::toString()  {
	return "ProductEmployee";
}
Object* ProductEmployeeParser::parse(std::string input)  {
	Object* reOject = nullptr;
	std::stringstream ss(input);
	std::string obj1, obj2;
	int productCount = 0, paymentPerProduct = 0;
	getline(ss, obj1, ',');
	getline(ss, obj2);

	int splitPosition;
	splitPosition = obj1.find_first_of('=');
	productCount = stoi(obj1.substr(splitPosition + 1));

	splitPosition = obj2.find_first_of('=');
	paymentPerProduct = stoi(obj2.substr(splitPosition + 1));

	reOject = new ProductEmployee(productCount, paymentPerProduct);

	return new ProductEmployee(productCount, paymentPerProduct);;
}
std::string ProductEmployeeParser::parsedObjectName()  {
	return "ProductEmployee";
}