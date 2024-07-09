#pragma once
#include"IParsable.h"
#include"DailyEmployee.h"
class DailyEmployeeParser : public IParsable {
public:
	std::string toString() override;
	Object* parse(std::string input) override;
	std::string parsedObjectName() override;
};