#include "Array.hpp"

void testLeak() {
	srand(time(NULL));

    std::cout << "\n------ a test ------\n" << std::endl;
	Array<int> a(5);
	for (unsigned int i = 0; i < a.size(); i++)
		a[i] = rand() % 100;
	// for (unsigned int i = 0; i < a.size(); i++)
	// 	std::cout << a[i] << std::endl;
    a.print();
	
    std::cout << "\n------ b test ------\n" << std::endl;
	Array<int> b(a);
    b.print();
	// for (unsigned int i = 0; i < b.size(); i++)
	// 	std::cout << b[i] << std::endl;
	
    std::cout << "\n------ c test ------\n" << std::endl;
	Array<int> c;
	c = b;
    c.print();
	// for (unsigned int i = 0; i < c.size(); i++)
	// 	std::cout << c[i] << std::endl;

    std::cout << "\n------ addres ------\n" << std::endl;
    std::cout << "a : " << &a << std::endl;
    std::cout << "b : " << &b << std::endl;
    std::cout << "c : " << &c << std::endl;

	std::cout << "\n\ntest deep copy" << std::endl;
	a[0] = 0;
	std::cout << a[0] << ", " << b[0] << ", " << c[0] << "\n" << std::endl;
	
	try {
		std::cout << c[100] << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

int main() {

	testLeak();

	system("leaks a.out");

	return 0;
}