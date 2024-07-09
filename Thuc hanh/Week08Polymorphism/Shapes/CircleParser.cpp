#include "CircleParser.h"
#include"IParsable.h"
#include"Circle.h"
#include"Utils.h"

//---
std::string CircleParser::toString() {
    return "Circle";
}
Object* CircleParser::parse(std::string input) {
	std::vector<std::string> token = Utils::String::split(input, "=");
	std::cout << token[1];
	return new Circle(stoi(token[1]));
}