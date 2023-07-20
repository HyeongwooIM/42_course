#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <algorithm>
# include <vector>

class Span {
	private:
		std::vector<int>	_container;
		unsigned int		_size;
	public:
		Span();
		Span(unsigned int n);
		Span(Span const &copy);
		~Span();
		Span &operator=(Span const &copy);

		void	addNumber(int n);
		void	addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		int		shortestSpan();
		int		longestSpan();

		class ContainerFullException : public std::exception {
			const char *what() const throw();
		};

		class ContainerNotEnoughException : public std::exception {
			const char *what() const throw();
		};
	
};

template <typename T>
	T const &min(T const &a, T const &b) {
		return (a < b ? a : b);
	};

# endif