#include "readFileCSV1.h"


std::vector<std::string> ReadFileCSV1::getAll(std::string namefile) {

	std::vector<std::string> data;
	std::ifstream fin;
	fin.open(namefile + ".txt", std::ios::in);
	if (!fin) {
		std::cout << "Can't open file!" << std::endl;
	}
	else {
		std::string line;
		while (getline(fin, line)) {
			data.push_back(line);
		}
	}
	fin.close();
	return data;
}