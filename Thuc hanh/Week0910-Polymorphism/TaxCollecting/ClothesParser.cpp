#include "ClothesParser.h"

Object1* ClothesParser::parse(std::string input) {
	std::vector<std::string> token = Utils1::String::split(input, ", ");
	std::vector<std::string> ID = Utils1::String::split(token[0], "=");
	std::vector<std::string> Area = Utils1::String::split(token[1], "=");
	return new Clothes(ID[1], stoi(Area[1]));
}

std::string ClothesParser::toString() {
	return "Clothes";
}