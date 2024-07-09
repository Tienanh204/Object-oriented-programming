#pragma once
#include"Object1.h"

class Integer1 : public Object1 {
private:
	int _value;
public:
	Integer1();
	Integer1(int value);
	int value();
	void setValue(int value);
	std::string toString();
};
