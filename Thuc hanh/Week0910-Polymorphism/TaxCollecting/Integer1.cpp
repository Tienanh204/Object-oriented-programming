#include "Integer1.h"


Integer1::Integer1() {
	_value = 0;
}

Integer1::Integer1(int value) {
	_value = value;
}

int Integer1::value() {
	return _value;
}

void Integer1::setValue(int value) {
	_value = value;
}

std::string Integer1::toString() {
	return "Integer";
}