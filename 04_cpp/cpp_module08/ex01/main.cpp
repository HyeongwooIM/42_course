#include "Span.hpp"

int main() {

	try{
	Span sp = Span(8);
	std::vector<int> addNumbers;

    addNumbers.push_back(10);
    addNumbers.push_back(20);
    addNumbers.push_back(30);	
	sp.addNumber(addNumbers.begin(), addNumbers.end());
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}