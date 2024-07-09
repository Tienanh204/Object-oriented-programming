#pragma once
#include"Object.h"
#include"IParsable.h"

class ParserFactory : public Object
{
public:
    std::string toString() override;
    IParsable* create(std::string type);
};
