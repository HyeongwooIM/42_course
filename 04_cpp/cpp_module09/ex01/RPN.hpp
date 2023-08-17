#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <stack>

class RPN{
	private:
		std::stack<ssize_t> _stack;
		std::string	_arg;
		ssize_t _tmp1;
		ssize_t _tmp2;

		RPN(const RPN& src);
		RPN& operator=(const RPN& rhs);
		void plus();
		void minus();
		void mult();
		void divide();

	public:
		~RPN();
		RPN();
		void reverseCalculator();
		void setArg(char *arg);
};

#endif