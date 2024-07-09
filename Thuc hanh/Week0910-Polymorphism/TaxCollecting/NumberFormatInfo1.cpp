#include "NumberFormatInfo1.h"

std::string NumberFormatInfo1::currencyDecimalSeparator() {
	return _currencyDecimalSeparator;
}
std::string NumberFormatInfo1::currencySymbol() {
	return _currencySymbol;
}
int NumberFormatInfo1::currencyPositive() {
	return _currencyPositive;
}
std::string NumberFormatInfo1::currencyPositiveFormat() {
	return _currencyPositiveFormat;
}

std::string NumberFormatInfo1::toString() {
	return "NumberFormatInfo";
}