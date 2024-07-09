#include "Idea.h"

int Idea::getDevMonths() const
{
    return _devMonths;
}

void Idea::setDevMonths(int devMonths)
{
    _devMonths = devMonths;
}

std::string Idea::getNameProject() {
    return _nameProject;
};

void Idea::setNameProject(std::string nameProject) {
    _nameProject = nameProject;
};

std::string Idea::toString() {
    return "Phat trien: " + 
        std::to_string(getDevMonths()) + 
        " thang";
}

Idea::Idea() {};
Idea::Idea(std::string nameProject, int devMonths) {
    _nameProject = nameProject;
    _devMonths = devMonths;
}

double Idea::Funding() {
    return _devMonths * 2200;
}

std::string Idea::parsedProjectType() {
    return "Y tuong";
}

