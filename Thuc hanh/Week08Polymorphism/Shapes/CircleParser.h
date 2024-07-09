#pragma once
#include"IParsable.h"

class CircleParser : public IParsable {
public:
    std::string toString() override;
    Object* parse(std::string input) override;
};