#ifndef PMERGEME_HPP
	#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <sstream>
#include <deque>
#include <iomanip>
#include <utility>
#include <algorithm>
#include <sys/time.h>

class PmergeMe {
    private:
        PmergeMe();
        PmergeMe(const PmergeMe& src);
        PmergeMe &operator=(const PmergeMe& rhs);
        std::vector<int> _vec_nums;
        std::deque<int> _deq_nums;

    public:
        PmergeMe(std::vector<int> nums);


};

void print_vector(std::vector<int> nums, std::string str);
bool cmp_func(const std::pair<int, int>& a, const std::pair<int, int>& b);
std::vector<unsigned int> vec_jacob_create(unsigned int len);
std::deque<unsigned int> deq_jacob_create(unsigned int len);
unsigned int jacob(unsigned int num);

template<class Iter>
void merge_sort(Iter first, Iter last)
{

    if (last - first > 1) {
        Iter middle = first + (last - first) / 2;
        merge_sort(first, middle);
        merge_sort(middle, last);
        std::inplace_merge(first, middle, last, cmp_func);
    }
};

template<typename container>
size_t binary_search(container &c, typename container::iterator low, typename container::iterator high, typename container::value_type &to_find) {
    typename container::iterator middle = low + std::distance(low, high) / 2;

    if (std::distance(low, high) <= 1 || *middle == to_find)
    {
        if (to_find <= *middle)
            return (std::distance(c.begin(), middle));
			// c.insert(middle, to_find);
        else
            return (std::distance(c.begin(), middle + 1));
            // c.insert(middle + 1, to_find);
    }
    else if (*middle > to_find) {
        return binary_search(c, low, middle, to_find);
    } else if (*middle < to_find) {
        return  binary_search(c, middle, high, to_find);
    }
    else {
        // c.insert(middle, to_find);    
		// std::cout << "HOHO" << std::endl;
		return (std::distance(c.begin(), middle));
	}
};


#endif