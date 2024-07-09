#pragma once
#include"Object.h"

class NumberFormatInfo : public Object {
private:
	std::string _currencyDecimalSeparator = ".";
	std::string _currencySymbol = "$";

	int _currencyPositive = 3;				// 0		1		2		3
	std::string _currencyPositiveFormat = "$n"; // "$n"		"n$"	"$ n"	"n $"
public:
	std::string currencyDecimalSeparator();
	std::string currencySymbol();
	int currencyPositive();
	std::string currencyPositiveFormat();
public:
	std::string toString();
};