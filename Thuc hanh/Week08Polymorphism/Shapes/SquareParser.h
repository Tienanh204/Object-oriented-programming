#pragma once
#include"IParsable.h"

class SquareParser : public IParsable {
public:
    std::string toString() override;
    Object* parse(std::string input) override;
};
