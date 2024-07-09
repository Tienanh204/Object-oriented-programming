#include "JewelryParser.h"


Object1* JewelryParser::parse(std::string input) {
	std::vector<std::string> token = Utils1::String::split(input, ", ");
	std::vector<std::string> ID = Utils1::String::split(token[0], "=");
	std::vector<std::string> Area = Utils1::String::split(token[1], "=");
	std::vector<std::string> SecurityFee = Utils1::String::split(token[2], "=");
	return new Jewelry(ID[1], stoi(Area[1]), stoi(SecurityFee[1]));
}

std::string JewelryParser::toString() {
	return "Jewelry";
}