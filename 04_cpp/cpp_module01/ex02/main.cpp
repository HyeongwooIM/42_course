#include <iostream>

void main2()
{
	std::string stringVAR = "HI THIS IS BRAIN";
	std::string stringCopy = stringVAR;
	std::string* stringPTR = &stringVAR;
	std::string& stringREF = stringVAR;

	std::cout << "stringVAR: " << &stringVAR << std::endl;
	std::cout << "stringVAR2: " << &stringCopy << std::endl;
	std::cout << "stringPTR: " << &stringPTR << std::endl;
	std::cout << "stringREF: " << &stringREF << std::endl;

	std::cout << "stringVAR: " << stringVAR << std::endl;
	std::cout << "stringVAR2: " << stringCopy << std::endl;
	std::cout << "stringPTR: " << *stringPTR << std::endl;
	std::cout << "stringREF: " << stringREF << std::endl;
}

int main(void) {
	main2();
	system("leaks Brain");
}
