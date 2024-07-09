#pragma once
#include"Object.h"

class IProject: public Object
{
public:
	virtual std::string getNameProject() = 0;
	virtual std::string parsedProjectType() = 0;
	virtual double Funding() = 0;
};


