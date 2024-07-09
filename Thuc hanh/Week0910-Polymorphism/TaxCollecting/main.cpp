#pragma once
#include"Object1.h"
#include"IParsable1.h"
#include"ParserFactory1.h"
#include"ReadFileCSV1.h"
#include"IntegerToCurrencyConverter1.h"
#include"NumberFormatInfo1.h"
#include"Utils1.h"
#include"Integer1.h"
#include"Sorted1.h"
#include"rentedTable.h"

int main() {
	ReadFileCSV1 readFile;
	std::vector<std::string> lines = readFile.getAll("RentMay24");

	std::vector<ITaxCollecting*> Tax;
	ParserFactory1 factory;

	for (auto& line : lines) {
		int slsplitPosition = line.find_first_of(" ");
		std::string type = line.substr(0, slsplitPosition);
		IParsable1* parse = factory.create(type);

		std::string data = line.substr(slsplitPosition + 1, line.size() - slsplitPosition - 1);
		ITaxCollecting* itax = dynamic_cast<ITaxCollecting*> (parse->parse(data));

		Tax.push_back(itax);
	}

	//Sorted
	SelectionSort1::byRentAscerd(Tax);

	std::vector<std::string> _headers = {
		"STT",
		"Ma sap",
		"Loai",
		"Dien tich",
		"Tien / m2",
		"Tien mat bang",
		"Phi khac",
		"Tong cong",
	};

	std::vector<int> _columnSizes = { 3, 6, 10, 10, 10, 20, 15, 10 };
	rentedTable1 table(_headers, _columnSizes);
	std::string infor = table.convert(Tax);


	std::cout << "Bao cao thu tien thue mat bang cho Ben Thanh" << std::endl;
	std::cout << "Thang: 05 / 2024" << std::endl << std::endl;
	std::cout << infor << std::endl;

	IntegerToCurrencyConverter1 converter;
	double TotalRent = 0;
	for (auto& tax : Tax) {
		TotalRent += tax->Total();
	}
	Integer1* value = new Integer1(TotalRent);
	std::cout << std::endl;
	std::cout << "Tong kinh phi tai tro: " << converter.convert(value) << '\n';
}