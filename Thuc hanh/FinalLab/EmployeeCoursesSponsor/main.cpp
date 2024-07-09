#include"Object.h"
#include"IParsable.h"
#include"AwakenPower.h"
#include"FinancialFreedom.h"
#include"IntegerToCurrencyConverter.h"
#include"readFile.h"
#include"SelfDevelopment.h"
#include"ICourses.h"
#include"ParserFactory.h"
#include"Utlis.h"
#include"CoureseTable.h"
#include"Integer.h"
int main() {
	ReadFile readFile;
	std::vector<std::string> lines = readFile.getAll("May2024Proposals");

	std::vector<ICourses*> coures;
	ParserFactory factory;

	for (int i = 0;i< lines.size() - 1; i+=2) {
		vector<string> inforPerson = Utils::String::split(lines[i], ": ");
		vector<string> infroCourese = Utils::String::split(lines[i + 1], ": ");

		vector<string> tempcoureses = Utils::String::split(infroCourese[1], ", ");
		vector<string> coureses = Utils::String::split(tempcoureses[0], "=");

		IParsable* parse = factory.create(coureses[1]);
		string data = inforPerson[1] + ", " + tempcoureses[1];

		ICourses* itax = dynamic_cast<ICourses*> (parse->parse(data));

		coures.push_back(itax);
	}

	std::vector<std::string> _headers = {
		"STT",
		"Nhan vien",
		"Thap niem",
		"Khoa hoc",
		"Chi phi",
		"Ho tro",
		"Thanh tien",
	};

	std::vector<int> _columnSizes = { 3, 6, 10, 10, 10, 20, 15};
	CoureseTable table(_headers, _columnSizes);
	std::string infor = table.convert(coures);


	std::cout << "Chuong trinh tai tro khoa hoc cho nhan vien 05/2024" << std::endl;
	std::cout << "Dang doc cac de nghi tu tap tin May2024Proposals.txt" << std::endl;
	std::cout << "Tim thay 3 de nghi ho tro chi phi tham gia khoa hoc" << std::endl << std::endl;
	std::cout << infor << std::endl;

	IntegerToCurrencyConverter converter;
	double TotalRent = 0;
	for (auto& it : coures) {
		TotalRent += it->getCost();
	}
	Integer* value = new Integer(TotalRent);
	std::cout << std::endl;
	std::cout << "Tong kinh phi tai tro: " << converter.convert(value) << '\n';
}
