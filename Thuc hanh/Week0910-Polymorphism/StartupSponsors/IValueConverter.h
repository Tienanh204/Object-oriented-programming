#pragma once
#include"Object.h"

class IValueConverter :public Object {
public:
	virtual std::string convert(Object* obj) = 0;
};


