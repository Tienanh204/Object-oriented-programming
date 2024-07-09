#pragma once
#include"Object.h"
#include"IParsable.h"

class ParerAwakenPower : public IParsable {
public:
    string toString() override;
    Object* parse(std::string input);
};