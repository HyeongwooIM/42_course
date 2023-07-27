#include "RPN.hpp"


int main(int ac, char** av)
{
	if (ac != 2) {
		std::cout << "[Error] : Bad argument" << std::endl;
		return (1);
	}
	try{
		RPN rpn;
		rpn.setArg(av[1]);
		rpn.reverseCalculator();
	} catch(std::exception& e){
		std::cout << e.what() << std::endl;
	}
}