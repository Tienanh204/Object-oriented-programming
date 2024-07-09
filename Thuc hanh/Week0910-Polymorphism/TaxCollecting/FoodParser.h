#pragma once
#include"Object1.h"
#include"IParsable1.h"
#include"Utils1.h"
#include"Clothes.h"
#include"Food.h"

class FoodParser : public IParsable1
{
public:
	Object1* parse(std::string input) override;
	std::string toString() override;

};

