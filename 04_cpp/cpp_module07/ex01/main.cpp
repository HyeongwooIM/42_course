#include "iter.hpp"

int main(void) {
	int 		array1[] = {1, 2, 3, 4, 5};
	std::string	array2[5] = {"one", "two", "three", "four", "five"};

	::iter(array1, 5, print);
	::iter(array2, 5, print);

	return 0;
}