#pragma once
#include"IParsable.h"
#include"Manager.h"

class ManagerParser : public IParsable {
public:
	std::string toString() override;
	std::string parsedObjectName();
	Object* parse(std::string input) override;
};
