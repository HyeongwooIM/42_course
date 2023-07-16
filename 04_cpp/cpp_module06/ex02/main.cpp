#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

void testLeak()
{
	Base *base = generate();

	identify(base);
	identify(*base);

	delete base;
}

int main()
{
	testLeak();

	system("leaks identify");

	return 0;
}