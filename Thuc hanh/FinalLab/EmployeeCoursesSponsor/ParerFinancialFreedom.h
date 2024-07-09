#pragma once
#include"Object.h"
#include"IParsable.h"

class ParerFinancialFreedom : public IParsable {
public:
    string toString() override;
    Object* parse(std::string input);
};

