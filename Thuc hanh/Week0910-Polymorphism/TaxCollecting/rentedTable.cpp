#include "rentedTable.h"


rentedTable1::rentedTable1() {};
rentedTable1::rentedTable1(std::vector<std::string> headers, std::vector<int> columnSizes) {
    _headers = headers;
    _columnSizes = columnSizes;
}

std::string rentedTable1::convert(std::vector<ITaxCollecting*> Tax) {
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

std::string rentedTable1::RentedToRowConverter::convert(ITaxCollecting* project) {
    std::ostringstream result;
    IntegerToCurrencyConverter1 converter;

    result << std::setw(_columnSizes[1]) << std::left << project->IDRent() << " | ";
    result << std::setw(_columnSizes[2]) << std::left << project->toString() << " | ";

    result << std::setw(_columnSizes[3]) << std::left << std::to_string((int)project->AreaRent()) + " m2" << " | ";

    Integer1* value = new Integer1(560);
    result << std::setw(_columnSizes[4]) << std::left << "560.000" << " | ";

    value = new Integer1(project->LeaseholdCash());
    result << std::setw(_columnSizes[5]) << std::left << converter.convertWithoutSymbol(value) << " | ";

    value = new Integer1(project->OtherCosts());
    result << std::setw(_columnSizes[6]) << std::left << converter.convertWithoutSymbol(value) << " | ";

    value = new Integer1(project->Total());
    result << std::setw(_columnSizes[7]) << std::left << converter.convert(value);

    return result.str();
}