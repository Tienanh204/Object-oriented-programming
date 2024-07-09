#include "RectangleParser.h"
#include"IParsable.h"
#include"Rectangle.h"
#include"Utils.h"

std::string RectangleParser::toString() {
    return "Rectangle";
}
Object* RectangleParser::parse(std::string input) {
	std::vector<std::string> token = Utils::String::split(input, ", ");
	std::vector<std::string> width = Utils::String::split(token[0], "=");
	std::vector<std::string> height = Utils::String::split(token[1], "=");
	return new Rectangle(stoi(width[1]), stoi(height[1]));
}
