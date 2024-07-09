#pragma once
#include"Object.h"
#include"IParsable.h"

class IdeaParser: public IParsable
{
public:
	Object* parse(std::string input);
	std::string toString();

};

