#pragma once
#include"Object.h"
class IParsable : public Object
{
public:
    virtual Object* parse(std::string input) = 0;
};

