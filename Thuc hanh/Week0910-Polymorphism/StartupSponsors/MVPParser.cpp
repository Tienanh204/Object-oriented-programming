#include "MVPParser.h"
#include "IdeaParser.h"
#include"Object.h"
#include"Utils.h"
#include"MVP.h"


Object* MVPParser::parse(std::string input) {
	std::vector<std::string> token = Utils::String::split(input, ", ");
	std::vector<std::string> runMonths = Utils::String::split(token[1], "=");
	std::vector<std::string> marketing = Utils::String::split(token[2], "=");
	return new MVP(token[0], stoi(runMonths[1]), stoi(marketing[1]));
}

std::string MVPParser::toString() {
	return "Mvp";
}

