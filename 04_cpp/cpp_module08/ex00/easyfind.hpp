#ifndef EASYFIND_H
# define EASYFIND_H

# include <algorithm>

class NotFoundException : public std::exception {	
	public:
		const char* what() const throw() { return "Value not found"; }
};

template<typename T>
typename T::iterator easyfind(T &src, int toFind)
{
	typename T::iterator it = std::find(src.begin(), src.end(), toFind);
	if (it == src.end())
		throw NotFoundException();
	return it;
}

#endif