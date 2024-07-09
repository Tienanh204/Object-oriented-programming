#pragma once
#include"Object.h"
#include"IParsable.h"

class ParserFactory : public Object {
public:
    ParserFactory();
    std::string toString();
    IParsable* create(std::string name);
};

