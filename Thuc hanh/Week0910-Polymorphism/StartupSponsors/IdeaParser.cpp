#include "IdeaParser.h"
#include"Object.h"
#include"Utils.h"
#include"Idea.h"

Object* IdeaParser::parse(std::string input) {
	std::vector<std::string> token = Utils::String::split(input, ", ");
	std::vector<std::string> devMonths = Utils::String::split(token[1], "=");
	return new Idea(token[0], stoi(devMonths[1]));
}

std::string IdeaParser::toString() {
	return "Idea";
}