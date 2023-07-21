#include "Span.hpp"

Span::Span(): _size(0) {
}

Span::Span(unsigned int n): _size(n) {
}

Span::Span(const Span &src): 
	_container(src._container)
	, _size(src._size) {
}

Span::~Span() {
}

Span &Span::operator=(const Span &rhs) {
	if (this != &rhs) {
		_container = rhs._container;
		_size = rhs._size;
	}
	return *this;
}

void Span::addNumber(int n) {
	if (_container.size() >= _size)
		throw ContainerFullException();
	_container.push_back(n);
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	if (_container.size() + (end - begin) > _size) 
		throw ContainerFullException();
	_container.insert(_container.end(), begin, end);
}

int Span::shortestSpan() {
	if (_container.size() < 2)
		throw ContainerNotEnoughException();
	std::vector<int>	tmp(_container);
	std::sort(tmp.begin(), tmp.end());
	int	min = tmp[1] - tmp[0];
	for (unsigned int i = 1; i < tmp.size() - 1; i++) {
		min = ::min(min, tmp[i + 1] - tmp[i]);
	}
	return min;
}

int Span::longestSpan() {
	if (_container.size() < 2)
		throw ContainerNotEnoughException();
	std::vector<int>	tmp(_container);
	std::sort(tmp.begin(), tmp.end());
	return tmp.back() - tmp.front();
}

const char *Span::ContainerFullException::what() const throw() {
	return "Container is full";
}

const char *Span::ContainerNotEnoughException::what() const throw() {
	return "Container is not enough";
}
