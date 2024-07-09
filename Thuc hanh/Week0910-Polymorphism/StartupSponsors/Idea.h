#pragma once
#include"IProject.h"
class Idea : public IProject
{
private:
    int _devMonths;
    std::string _nameProject;

public:
    Idea();
    Idea(std::string nameProject, int devMonths);
    int getDevMonths() const;
    void setDevMonths(int devMonths);
    std::string getNameProject();
    void setNameProject(std::string nameProject);

    double Funding();
    std::string toString();
    std::string parsedProjectType();
};