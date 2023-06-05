#include <iostream>

int main(void) {
	std::string stringVAR = "HI THIS IS BRAIN";
	std::string stringCopy = stringVAR;		// stringVAR 값 복사, 저장
	std::string* stringPTR = &stringVAR;	// 포인터에 stringVAR 주소 저장
	std::string& stringREF = stringVAR;		// 레퍼런스는 stringVAR의 별명, stringVAR과 주소값은 같음

	// memory address
	std::cout << "stringVAR: " << &stringVAR << std::endl;
	std::cout << "stringVAR2: " << &stringCopy << std::endl;
	std::cout << "stringPTR: " << &stringPTR << std::endl;
	std::cout << "stringREF: " << &stringREF << std::endl;

	// value
	std::cout << "stringVAR: " << stringVAR << std::endl;
	std::cout << "stringVAR2: " << stringCopy << std::endl;
	std::cout << "stringPTR: " << *stringPTR << std::endl;
	std::cout << "stringREF: " << stringREF << std::endl;
	return 0;
}

/*
stringVAR: 0x7ff7bf41e450 // 
stringVAR2: 0x7ff7bf41e438
stringPTR: 0x7ff7bf41e420
stringREF: 0x7ff7bf41e450 // 레퍼런스는 stringVAR과 주소값이 같음

stringVAR: HI THIS IS BRAIN
stringVAR2: HI THIS IS BRAIN
stringPTR: HI THIS IS BRAIN
stringREF: HI THIS IS BRAIN
*/