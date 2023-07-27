#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
	std::string fileName("data.csv");	
	std::ifstream infile(fileName);
	if (!infile.is_open()) {
		std::cout << "[Error] : data.csv file open failed" << std::endl; 
		exit(1);
	}
	std::string line;
	std::getline(infile, line);
	if (line != "date,exchange_rate") {
		std::cout << "[Error] : Invalid file information." << std::endl; 
		exit(1);
	}
	while (std::getline(infile, line)) {
			std::istringstream iss(line);
			std::string dateString;
			float value;
			if (std::getline(iss, dateString, ',') && iss >> value) {
				dateString.erase(dateString.size());
			_csv[dateString] = value;
			std::cout << dateString << " -> " << value << std::endl;
		}
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
	: _dataBase(src._dataBase) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &rhs) {
	if (this == &rhs)
		return (*this);
	if (this->_dataBase != rhs._dataBase) {
		this->_dataBase = rhs._dataBase;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {}



// std::pair<std::string, float> BitcoinChange::makePair(std::string& str) {
	
// 	size_t adr = str.find(" | ");
// 	if (adr = std::string::nops)
// 		throw std::invalid_argument("Error : Not a positive value " + str);
// 	std::string date = checkDate(str.substr(0, adr));
// }

// std::string BitcoinChange::checkDate(std::string& str) {
// 	if (dateString.length() != 10 || dateString[4] != '-' || dateString[7] != '-')
//         throw std::invalid_argument("Error : Not a positive value " + str);

//     int year, month, day;
//     if (std::sscanf(dateString.c_str(), "%d-%d-%d", &year, &month, &day) != 3)
//         return false;
//     if (year < 1900 || month < 1 || month > 12 || day < 1 || day > 31)
//         return false;

//     std::tm date = {};

//     date.tm_year = year - 1900; // tm_year is years since 1900.
//     date.tm_mon = month - 1;    // tm_mon is months since January (0-based).
//     date.tm_mday = day;         // tm_mday is day of the month.

//     // Set tm_isdst to -1 to let mktime determine if daylight saving time is in effect.
//     date.tm_isdst = -1;

//     // Call mktime to normalize the date and check if it is valid.
//     // mktime returns (time_t)-1 if the date is invalid.
//     std::time_t time = std::mktime(&date);
//     return time != (std::time_t)-1;
// }

// bool BitcoinChange::isValidDate(const std::string& dateString, int& year, int& month, int& day) {
// 	if (dateString.length() != 10 || dateString[4] != '-' || dateString[7] != '-')
//         return false;
// }

void BitcoinExchange::addData(std::string& line) {
	std::istringstream iss(line);
	std::string dateString;
	int year, month, day;
	float value;

	if (std::getline(iss, dateString, '|') && iss >> value) {
		dateString.erase(dateString.size() - 1);
		if (value > 1000 || value < 0)
			throw std::invalid_argument("Error : Not a positive value " + line);
        if (dateString.length() != 10 || dateString[4] != '-' || dateString[7] != '-')
			throw std::invalid_argument("Error : Not a positive date " + line);
		if (std::sscanf(dateString.c_str(), "%d-%d-%d", &year, &month, &day) != 3)
			throw std::invalid_argument("Error : Not a positive date " + line);
		if (year < 1970 || month < 1 || month > 12 || day < 1 || day > 31)
			throw std::invalid_argument("Error : Not a positive date " + line);
		std::tm date = {};
		date.tm_year = year - 1900; // tm_year is years since 1900.
		date.tm_mon = month - 1;    // tm_mon is months since January (0-based).
    	date.tm_mday = day;         // tm_mday is day of the month.
		// Set tm_isdst to -1 to let mktime determine if daylight saving time is in effect.
		date.tm_isdst = -1;
		std::time_t time = std::mktime(&date);
		std::tm* beforeDate = std::localtime(&time);
		if ( year - 1900 != beforeDate->tm_year || month - 1 != beforeDate->tm_mon
			|| day != beforeDate->tm_mday) {
			throw std::invalid_argument("Error : Not a positive date " + line);
		}
		std::map<std::string, float>::iterator it = _csv.lower_bound(dateString);
        _dataBase[dateString] = value;
		if (_csv.end() == it)
			throw std::invalid_argument("Error : Can't find vlaue " + line);
		if (_csv.begin() != it && it->first != dateString)
			--it;
		std::cout << it->first << std::endl;
		std::cout << dateString << " => " << value << " * " << it->second << " = " << value * it->second << std::endl;
    } else 
        throw std::invalid_argument("Error : Can't find '|' " + line);
}

void BitcoinExchange::printAllDataBase() const {
    std::cout << "Data in _dataBase:" << std::endl;
    for (std::map<std::string, float>::const_iterator it = _dataBase.begin(); it != _dataBase.end(); ++it) {
        const std::string& key = it->first;
        const float& value = it->second;
        std::cout << key << " -> " << value << std::endl;
    }
}
