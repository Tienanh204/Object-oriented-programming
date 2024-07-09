#include "NumberFormatInfo.h"
#include"Object.h"
std::string NumberFormatInfo::currencyDecimalSeparator() {
    return _currencyDecimalSeparator;
}
std::string NumberFormatInfo::currencySymbol() {
    return _currencySymbol;
}
int NumberFormatInfo::currencyPositive() {
    return _currencyPositive;
}
std::string NumberFormatInfo::currencyPositiveFormat() {
    return _currencyPositiveFormat;
}

std::string NumberFormatInfo::toString() {
    return "NumberFormatInfo";
}
