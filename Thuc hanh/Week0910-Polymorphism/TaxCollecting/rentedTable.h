#pragma once
#include"Object1.h"
#include"ITaxCollecting.h"
#include"IntegerToCurrencyConverter1.h"
#include"Integer1.h"
#include<iomanip>

class rentedTable1
{
private:
    std::vector<std::string> _headers;
    std::vector<int> _columnSizes;
public:
    rentedTable1();
    rentedTable1(std::vector<std::string> headers, std::vector<int> columnSizes);
    std::string convert(std::vector<ITaxCollecting*> Tax);
private:
    class RentedToRowConverter {
    private:
        std::vector<int> _columnSizes;
    public:
        RentedToRowConverter() {};
        RentedToRowConverter(std::vector<int> columnSizes) :_columnSizes(columnSizes) {};
        std::string convert(ITaxCollecting* project);
    };
};
