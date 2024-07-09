#include "Integer.h"

Integer::Integer() {
	_value = 0;
}
Integer::Integer(int value) {
	_value = value;
}
int Integer::value() {
	return _value;
}
void Integer::setValue(int value) {
	_value = value;
}
std::string Integer::toString() {
	return "Integer";
}