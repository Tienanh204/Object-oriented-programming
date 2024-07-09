#pragma once
#include"Object1.h"
#include"NumberFormatInfo1.h"
#include <regex>
#include"Integer1.h"

class IntegerToCurrencyConverter1 {
public:
	std::string	convert(Object1* object);
	std::string convertWithoutSymbol(Object1* object);
};
