#pragma once
#include"Object1.h"
#include"IParsable1.h"
#include"Utils1.h"
#include"Clothes.h"
class ClothesParser : public IParsable1
{
public:
	Object1* parse(std::string input) override;
	std::string toString() override;

};

