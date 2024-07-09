#pragma once
#include"Object1.h"
class ITaxCollecting : public Object1
{
public:
	virtual double LeaseholdCash() = 0;
	virtual double OtherCosts() = 0;
	virtual double Total() = 0;
	virtual std::string IDRent() = 0;
	virtual double AreaRent() = 0;
};

