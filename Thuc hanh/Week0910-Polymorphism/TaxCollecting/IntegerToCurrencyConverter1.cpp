#include "IntegerToCurrencyConverter1.h"
#include <cmath>

std::string IntegerToCurrencyConverter1::convert(Object1* object) {
	auto number = dynamic_cast<Integer1*>(object);
	int value = number->value();

	std::stringstream builder;
	NumberFormatInfo1 info;
	int count = 0;
	int temp_count = 0;

	if (value == 0) {
		return "0";
	}

	int temp_value = value;
	while (temp_value!=0)
	{
		temp_value /= 10;
		temp_count++;
	}

	while (value != 0) {
		int lastDigit = value % 10;
		builder << lastDigit;

		count++;

		if (count == 3) {
			builder << info.currencyDecimalSeparator();
			count = 0;
		}
		value /= 10;
	}

	std::string numberSeparated = builder.str(); // "000.000.1"
	reverse(numberSeparated.begin(), numberSeparated.end());

	std::string format = info.currencyPositiveFormat();//n $" ==> "1.000.000 d"
	std::string symbol = info.currencySymbol(); // "d"
	std::string result = std::regex_replace(format, std::regex("n"), numberSeparated);//Trong chuoi foemat thay the n bang numberSeparated
	result = std::regex_replace(result, std::regex("\\$"), symbol);

	if (temp_count % 3 == 0) {
		result = result.substr(1, result.size());
	}
	return result;
}

std::string IntegerToCurrencyConverter1::convertWithoutSymbol(Object1* object) {
	auto number = dynamic_cast<Integer1*>(object);
	int value = number->value();

	std::stringstream builder;
	NumberFormatInfo1 info;
	int count = 0;
	int temp_count = 0;

	if (value == 0) {
		return "0";
	}

	int temp_value = value;
	while (temp_value != 0)
	{
		temp_value /= 10;
		temp_count++;
	}

	while (value != 0) {
		int lastDigit = value % 10;
		builder << lastDigit;

		count++;

		if (count == 3) {
			builder << info.currencyDecimalSeparator();
			count = 0;
		}
		value /= 10;
	}
	std::string numberSeparated = builder.str(); // "000.000.1"
	reverse(numberSeparated.begin(), numberSeparated.end());

	if (temp_count % 3 == 0) {
		numberSeparated = numberSeparated.substr(1, numberSeparated.size());
	}
	return numberSeparated;
}