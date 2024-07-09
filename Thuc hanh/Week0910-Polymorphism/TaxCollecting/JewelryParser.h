
#pragma once
#include"Object1.h"
#include"IParsable1.h"
#include"Utils1.h"
#include"Jewelry.h"

class JewelryParser : public IParsable1
{
public:
	Object1* parse(std::string input) override;
	std::string toString() override;
};
