#include "SquareParser.h"
#include"IParsable.h"
#include"Square.h"
#include"Utils.h"

//---
std::string SquareParser::toString() {
    return "Square";
}
Object* SquareParser::parse(std::string input) {
	std::vector<std::string> token = Utils::String::split(input, "=");
	return new Square(stoi(token[1]));
}
