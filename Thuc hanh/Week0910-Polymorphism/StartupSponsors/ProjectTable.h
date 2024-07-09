#pragma once
#include"Object.h"
#include"IProject.h"
class ProjectTable
{
private:
	std::vector<std::string> _headers;
	std::vector<int> _columnSizes;
public:
	ProjectTable();
	ProjectTable(std::vector<std::string> headers, std::vector<int> columnSizes);
	std::string convert(std::vector<IProject*> students);
private:
    class ProjectToRowConverter {
    private:
        std::vector<int> _columnSizes;
    public:
        ProjectToRowConverter() {};
        ProjectToRowConverter(std::vector<int> columnSizes) :_columnSizes(columnSizes) {};
        std::string convert(IProject* project);
    };
};

