#pragma once
#include"Object.h"

class ICourses: public Object
{
public:
	virtual string getName() = 0;
	virtual string typePersion() = 0;
	virtual string counreses() = 0;
	virtual double getCost() = 0;
	virtual double help() = 0;
	virtual double total() = 0;
};

