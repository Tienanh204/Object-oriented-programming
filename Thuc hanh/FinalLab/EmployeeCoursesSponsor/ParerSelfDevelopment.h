#pragma once
#include"Object.h"
#include"IParsable.h"

class  ParerSelfDevelopment : public IParsable
{
public:
    string toString() override;
    Object* parse(std::string input);
};
