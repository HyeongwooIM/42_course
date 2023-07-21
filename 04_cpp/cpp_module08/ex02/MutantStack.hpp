#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <iostream>

template <typename T>
class MutantStack : public std::stack<T> {
	public:
		MutantStack() : std::stack<T>() {}
		MutantStack(MutantStack const &src) : std::stack<T>(src) {}
		~MutantStack() {}

		MutantStack &operator=(MutantStack const &rhs) {
			if (this != &rhs)
				std::stack<T>::operator=(rhs);
			return (*this);
		}

		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		iterator 			begin() { return std::stack<T>::c.begin(); }
		iterator			end() { return std::stack<T>::c.end(); }
		reverse_iterator	rbegin() { return std::stack<T>::c.rbegin(); }
		reverse_iterator	rend() { return std::stack<T>::c.rend(); }
};

#endif