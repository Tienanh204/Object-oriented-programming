#pragma once
#include"IParsable.h"

class RectangleParser : public IParsable {
public:
    std::string toString() override;
    Object* parse(std::string input) override;
};
