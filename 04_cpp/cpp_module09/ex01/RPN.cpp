#include "RPN.hpp"

RPN::RPN(){

}

RPN::~RPN(){

}

void RPN::setArg(char *str) {
	std::string tmp(str);
	_arg = str;
}

void RPN::mult() {
	_tmp1 = _stack.top();
	_stack.pop();
	_tmp2 = _stack.top();
	_stack.pop();
	_stack.push(_tmp1 * _tmp2);
}

void RPN::plus() {
	_tmp1 = _stack.top();
	_stack.pop();
	_tmp2 = _stack.top();
	_stack.pop();
	_stack.push(_tmp1 + _tmp2);
}

void RPN::minus() {
	_tmp1 = _stack.top();
	_stack.pop();
	_tmp2 = _stack.top();
	_stack.pop();
	_stack.push(_tmp1 - _tmp2);
}

void RPN::divide() {
	_tmp1 = _stack.top();
	_stack.pop();
	_tmp2 = _stack.top();
	_stack.pop();
	if (_tmp2 == 0)
		throw std::invalid_argument("Error : Can't divide zero");
	_stack.push(_tmp1 / _tmp2);
}

void RPN::reverseCalculator() {
	void	(RPN::*f[6])(void) = {&RPN::mult, &RPN::plus, &RPN::minus, &RPN::minus, &RPN::divide, &RPN::divide};
	std::string::iterator it = _arg.begin();
	int count = 0;

	while (it != _arg.end()) {
		while (*it == ' ')
			it++;
		if(*it == '/' || *it == '*' || *it == '+' || *it == '-') {
			if (_stack.size() < 2)
				throw std::invalid_argument("Error : Invalid Argument1");
			(this->*f[*it - 42])();
			++it;
		}
		else if (*it < '0' || *it > '9') {
			std::cout << *it << ";;;" << std::endl;
			throw std::invalid_argument("Error : Invalid Argument2");
			exit (1);
		} else {
			_stack.push(*it - 48);
			++it;
		}
		if (*it != ' ' && it != _arg.end()) {
			throw std::invalid_argument("Error : Invalid Argument3");
			exit (1);
		}
		count++;
	}
	if (count < 2)
		throw std::invalid_argument("Error : Too few arguments.");
	if (_stack.size() != 1)
		throw std::invalid_argument("Error : Stack size is not one");
	std::cout << "result : " << _stack.top() << std::endl;
}