#include "ParserFactory1.h"


IParsable1* ParserFactory1::create(std::string type) {
	std::map<std::string, IParsable1*> _container = {
		{ "Clothes", new ClothesParser() },
		{ "Food", new FoodParser() },
		{ "Jewelry", new JewelryParser() }
	};
	IParsable1* parse = _container[type];
	return parse;
}

std::string ParserFactory1::toString() {
	return "ParserFactory";
}