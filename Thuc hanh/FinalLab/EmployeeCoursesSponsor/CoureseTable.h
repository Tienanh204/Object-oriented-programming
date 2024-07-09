#pragma once
#include"Object.h"
#include"ICourses.h"
class CoureseTable
{
private:
    std::vector<std::string> _headers;
    std::vector<int> _columnSizes;
public:
    CoureseTable();
    CoureseTable(std::vector<std::string> headers, std::vector<int> columnSizes);
    std::string convert(std::vector<ICourses*> Tax);
private:
    class RentedToRowConverter {
    private:
        std::vector<int> _columnSizes;
    public:
        RentedToRowConverter() {};
        RentedToRowConverter(std::vector<int> columnSizes) :_columnSizes(columnSizes) {};
        std::string convert(ICourses* project);
    };
};

