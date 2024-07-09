#pragma once
#include"Object1.h"
#include"FoodParser.h"
#include"JewelryParser.h"
#include"ClothesParser.h"
#include"IParsable1.h"
#include<map>

class ParserFactory1 : public Object1
{
public:
	std::string toString() override;
	IParsable1* create(std::string type);
};
