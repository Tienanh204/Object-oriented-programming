#pragma once
#include"IParsable.h"
#include"ProductEmployee.h"

class ProductEmployeeParser : public IParsable {
public:
	std::string toString() override;
	Object* parse(std::string input) override;
	std::string parsedObjectName() override;
};