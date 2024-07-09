#include "FoodParser.h"

Object1* FoodParser::parse(std::string input) {
	std::vector<std::string> token = Utils1::String::split(input, ", ");
	std::vector<std::string> ID = Utils1::String::split(token[0], "=");
	std::vector<std::string> Area = Utils1::String::split(token[1], "=");
	std::vector<std::string> ColdStorage = Utils1::String::split(token[2], "=");
	return new Food(ID[1], stoi(Area[1]), stoi(ColdStorage[1]));
}

std::string FoodParser::toString() {
	return "Food";
}