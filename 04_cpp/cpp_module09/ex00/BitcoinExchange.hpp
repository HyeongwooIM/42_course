#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

class BitcoinExchange {
	public:
		void printAllDataBase() const;
		bool isValidDate(const std::string& dateString, int& year, int& month, int& day);
		void addData(std::string& line);
		std::string getData(std::string& path);
		std::pair<std::string, float> makePair(std::string& str);
		BitcoinExchange();
		~BitcoinExchange();

	private:
		std::map<std::string, float> _dataBase;
		BitcoinExchange(const BitcoinExchange& origin);
		BitcoinExchange& operator=(const BitcoinExchange& BitcoinExchange);

};

#endif