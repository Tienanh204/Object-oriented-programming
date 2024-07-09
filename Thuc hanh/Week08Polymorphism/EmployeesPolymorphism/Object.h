#pragma once
#include<iostream>
#include<string>
#include<cstring>
#include<sstream>
#include <regex>
#include<vector>
#include<map>

class Object {
public:
	virtual std::string toString() = 0;
};
