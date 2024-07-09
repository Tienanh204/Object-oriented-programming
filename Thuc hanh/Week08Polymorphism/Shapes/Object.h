#pragma once
#include<iostream>
#include<string>
#include<sstream>
#include<vector>

class Object {
public:
    virtual std::string toString() = 0;
};