#include "BitcoinExchange.hpp"
// Lower bound
// mktime

int main(int ac, char **av)
{
	if (ac != 2) {
		std::cout << "[Error] : Bad argument" << std::endl;
		return (1);
	}
	std::string fileName(av[1]);
	size_t dotPos = fileName.rfind('.');
	if (dotPos == std::string::npos) {
		std::cout << "[Error] : Invalid file format. Valid file format -> .txt" << std::endl;
		return (1);
	}
	
	std::string tmp = fileName.substr(dotPos);
	if (tmp != ".txt") {
		std::cout << "[Error] : Invalid file format. Valid file format -> .txt" << std::endl;
		return (1);
	}	
	std::ifstream infile(fileName);
	if (!infile.is_open()) {
		std::cout << "[Error] : file open failed." << std::endl;
		return (1);
	}
	std::string line;
	std::getline(infile, line);
	if (line != "date | value") {
		std::cout << "[Error] : Invalid file information." << std::endl;
		return (1);
	}
	BitcoinExchange bitCoin;
	while (std::getline(infile, line)) {
		try {
			// std::pair<std::string, float> pair = bitCoin.makePair(str);
			bitCoin.addData(line);
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	// bitCoin.printDataBase();
}

