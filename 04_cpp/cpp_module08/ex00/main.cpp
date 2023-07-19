#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

int main()
{
	std::vector<int> vec;
	std::list<int> lst;
	std::deque<int> dq;

	srand(time(NULL));
	for (int i = 0; i < 9; i++) {
		vec.push_back(rand() % 10);
		lst.push_back(rand() % 10);
		dq.push_back(rand() % 10);
	}
	try
	{
		std::cout << "found from vector: " << *(easyfind(vec, rand() % 10)) << std::endl;
		std::cout << "found from vector: " << *(easyfind(vec, rand() % 10)) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	try
	{
		std::cout << "found from list: " << *(easyfind(lst, rand() % 10)) << std::endl;
		std::cout << "found from list: " << *(easyfind(lst, rand() % 10)) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	try
	{
		std::cout << "found from deque: " << *(easyfind(dq, rand() % 10)) << std::endl;
		std::cout << "found from deque: " << *(easyfind(dq, rand() % 10)) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	return 0;
}