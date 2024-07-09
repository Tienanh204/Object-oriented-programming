#pragma once
#include"Object1.h"
class IParsable1 : public Object1
{
public:
	virtual Object1* parse(std::string input) = 0;
};

