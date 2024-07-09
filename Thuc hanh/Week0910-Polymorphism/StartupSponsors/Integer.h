#pragma once
#include"Object.h"

class Integer : public Object {
private:
	int _value;
public:
	Integer();
	Integer(int value);
	int value();
	void setValue(int value);
	std::string toString();
};
