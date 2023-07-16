#include "Bureaucrat.hpp"

int main() {
	Bureaucrat	max("max", 1);
	Form		form("form", 1, 1);

	std::cout << max << std::endl;
	std::cout << form << std::endl;

	std::cout << "\n<---valid test--->" << std::endl;
	try {
		max.signForm(form);
		std::cout << form << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n<---decrement--->" << std::endl;
	try {
		max.decrementGrade();
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n<---invalid test--->" << std::endl;
	try {
		// form.beSigned(max); // 이렇게 하면 catch로 빠져 아래 출력은 실행되지 않는다.
		max.signForm(form); // 이렇게 하면 signForm에서 catch로 빠지고 아래 출력은이 실행된다.
		std::cout << form << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}