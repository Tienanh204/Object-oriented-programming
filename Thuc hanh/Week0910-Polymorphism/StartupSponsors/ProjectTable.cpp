#include "ProjectTable.h"
#include"IProject.h"
#include"Object.h"
#include<iomanip>
#include"Integer.h"
#include"IntegerToCurrencyConverter.h"


ProjectTable::ProjectTable() {};
ProjectTable::ProjectTable(std::vector<std::string> headers, std::vector<int> columnSizes) {
	_headers = headers;
	_columnSizes = columnSizes;
}

std::string ProjectTable::convert(std::vector<IProject*> project) {
	std::stringstream result;
    for (size_t i = 0; i < _headers.size(); ++i) {
        result << std::setw(_columnSizes[i]) << std::left << _headers[i] << " | ";
    }
    result << "\n";

    for (size_t i = 0; i < _headers.size(); ++i) {
        result << std::string(_columnSizes[i] - 1, '-');
    }
    result << "\n";

    int i = 1;
    for (const auto& pro : project) {
        result << std::setw(_columnSizes[0]) << std::left << i << " | ";
        result << ProjectToRowConverter(_columnSizes).convert(pro) + "\n";
        i++;
    }
    return result.str();
}

std::string ProjectTable::ProjectToRowConverter::convert(IProject* project) {
    std::ostringstream result;
    IntegerToCurrencyConverter converter;

    result << std::setw(_columnSizes[1]) << std::left << project->parsedProjectType() << " | ";
    result << std::setw(_columnSizes[2]) << std::left << project->getNameProject() << " | ";
    result << std::setw(_columnSizes[3]) << std::left << project->toString() << " | ";

    Integer* value = new Integer(project->Funding());
    result << std::setw(_columnSizes[4]) << std::left << converter.convert(value);
    return result.str();
}