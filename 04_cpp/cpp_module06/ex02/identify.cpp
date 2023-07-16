#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void) {
	srand(time(NULL));

	try {
		switch(std::rand() % 3) {
			case 0:
				std::cout << "generate A" << std::endl;
				return new A;
			case 1:
				std::cout << "generate B" << std::endl;
				return new B;
			case 2:
				std::cout << "generate C" << std::endl;
				return new C;
		}
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return NULL;
}

void identify(Base* p) {
	if (p == NULL) {
		std::cout << "NULL" << std::endl;
		return ;
	}
	if (dynamic_cast<A *>(p)) {
		std::cout << "A" << std::endl;
		return ;
	}
	if (dynamic_cast<B *>(p)) {
		std::cout << "B" << std::endl;
		return ;
	}
	if (dynamic_cast<C *>(p)) {
		std::cout << "C" << std::endl;
		return ;
	}
}

void identify(Base& p) {
	Base	base;

	try {
		base = dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
		return ;
	}
	catch (std::exception &e) {
	}

	try {
		base = dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
		return ;
	}
	catch (std::exception &e) {
	}

	try {
		base = dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
		return ;
	}
	catch (std::exception &e) {
	}
}