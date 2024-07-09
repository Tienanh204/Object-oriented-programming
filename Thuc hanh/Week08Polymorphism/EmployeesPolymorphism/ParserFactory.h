#pragma once
#include"Object.h"
#include"IParsable.h"

class ParserFactory : public Object {
private:
	std::map<std::string, IParsable*> _container;
public:
	void registerWith(IParsable* parser);
	IParsable* create(std::string type);
	std::string toString();
};