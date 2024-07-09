#include"Object.h"
#include"IParsable.h"
#include"IProject.h"
#include"ParserFactory.h"
#include"Idea.h"
#include"MVP.h"
#include"IdeaParser.h"
#include"MVPParser.h"
#include"ProjectTable.h"
#include"ReadFileCSV.h"
#include"IntegerToCurrencyConverter.h"
#include"NumberFormatInfo.h"
#include"Utils.h"
#include"Sort.h"
#include"Integer.h"
int main() {
	ParserFactory factory;
	factory.registerWith(new IdeaParser());
	factory.registerWith(new MVPParser());

	ReadFileCSV readFile;
	std::vector<std::string> lines = readFile.getAll("MayProposals");

	std::vector<IProject*> projects;
	for (auto& line : lines) {
		std::vector<std::string> token = Utils::String::split(line, ": ");
		IParsable* parse = factory.create(token[0]);
		IProject* iproject = dynamic_cast<IProject*> (parse->parse(token[1]));
		projects.push_back(iproject);
	}

	//Sorted
	std::sort(projects.begin(), projects.end(), Sorted::byFundAscerd);

	//Table & print
	std::vector<std::string> _headers = { "STT","Loai du an", "Ten du an", "Thong tin", "Kinh phi"};
	std::vector<int> _columnSizes = { 3, 10, 15, 40, 30 };

	ProjectTable table(_headers, _columnSizes);
	std::string info = table.convert(projects);


	std::cout << "Ke hoac tai tro du an startup noi bo cong ty AlphaTech" << std::endl;
	std::cout << "Thang: 05/2024" << std::endl << std::endl;
	std::cout << info;

	IntegerToCurrencyConverter converter;
	double sumFunding = 0;
	for (const auto& pro : projects) {
		sumFunding += pro->Funding();
	}
	Integer* value = new Integer(sumFunding);
	std::cout << std::endl;
	std::cout<< "Tong kinh phi tai tro: " << converter.convert(value) << '\n';

	return 0;
}

