#include "CoureseTable.h"
#include"Object.h"
#include"Integer.h"
#include"IntegerToCurrencyConverter.h"
#include"ICourses.h"
#include<iomanip>

CoureseTable::CoureseTable() {};
CoureseTable::CoureseTable(std::vector<std::string> headers, std::vector<int> columnSizes) {
    _headers = headers;
    _columnSizes = columnSizes;
}

std::string CoureseTable::convert(std::vector<ICourses*> Tax) {
    std::stringstream result;
    for (size_t i = 0; i < _headers.size(); ++i) {
        result << std::setw(_columnSizes[i]) << std::left << _headers[i] << " | ";
    }
    result << std::endl;

    for (size_t i = 0; i < _headers.size(); ++i) {
        result << std::string(_columnSizes[i] + 3, '-');
    }
    result << std::endl;

    int i = 1;
    for (const auto& pro : Tax) {
        result << std::setw(_columnSizes[0]) << std::left << i << " | ";
        result << RentedToRowConverter(_columnSizes).convert(pro) << std::endl;
        i++;
    }
    return result.str();
}

std::string CoureseTable::RentedToRowConverter::convert(ICourses* project) {
    std::ostringstream result;
    IntegerToCurrencyConverter converter;

    result << std::setw(_columnSizes[1]) << std::left << project->getName() << " | ";
    result << std::setw(_columnSizes[2]) << std::left << project->typePersion() << " | ";

    result << std::setw(_columnSizes[3]) << std::left << project->toString() << " | ";

    Integer* value = new Integer(project->getCost());
    result << std::setw(_columnSizes[4]) << std::left << converter.convert(value) << " | ";

    value = new Integer(project->help());
    result << std::setw(_columnSizes[5]) << std::left << converter.convert(value) << " | ";

    value = new Integer(project->total());
    result << std::setw(_columnSizes[6]) << std::left << converter.convert(value) << " | ";

    return result.str();
}

