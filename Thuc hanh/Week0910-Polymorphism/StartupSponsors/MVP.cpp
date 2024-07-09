#include "MVP.h"
int MVP::getRunMonths() const
{
    return _runMonths;
}

void MVP::setRunMonths(int runMonths)
{
    _runMonths = runMonths;
}

int MVP::getMarketing() const
{
    return _marketing;
}

void MVP::setMarketing(int marketing)
{
    _marketing = marketing;
}

std::string MVP::getNameProject() {
    return _nameProject; 
};

void MVP::setNameProject(std::string nameProject) {
    _nameProject = nameProject; 
};

std::string MVP::toString() {
    return {
        "Van hanh: " + std::to_string(getRunMonths())
        + " thang. Marketing: "
        + std::to_string(getMarketing())
        + " thang"
    };
}

MVP::MVP() {};
MVP::MVP(std::string nameProject, int runMonths, int marketing) {
    _nameProject = nameProject;
    _runMonths = runMonths;
    _marketing = marketing;
}

double MVP::Funding() {
    return _runMonths * 930 + _marketing * 500;
}

std::string MVP::parsedProjectType() {
    return "San pham";
}