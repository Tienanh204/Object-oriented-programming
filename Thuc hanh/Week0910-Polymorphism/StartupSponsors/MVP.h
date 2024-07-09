#pragma once
#include"IProject.h"

class MVP : public IProject
{
private:
    std::string _nameProject;
    int _runMonths;
    int _marketing;

public:
    MVP();
    MVP(std::string nameProject, int runMonths, int marketing);
    int getRunMonths() const;
    void setRunMonths(int runMonths);
    int getMarketing() const;
    void setMarketing(int marketing);
    std::string getNameProject();
    void setNameProject(std::string nameProject);

    double Funding();
    std::string toString();
    std::string parsedProjectType();

};
