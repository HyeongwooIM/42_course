#include "PmergeMe.hpp"

#include <iostream>
#include <vector>
#include <sstream>
#include <deque>
#include <iomanip>
#include <utility>
#include <algorithm>
#include <sys/time.h>

int main(int ac, char **av) {

	if (ac <= 2) {
		std::cout << "Too low argument" << std::endl;
		return 1;
	}
	std::vector<int> nums;
	int num;
	nums.reserve(ac - 1); // 용량 할당 벡터는 처음 용량보다 큰 용량이 필요해질 시 초기보다 2배 큰 용량을 할당함. 할당 -> 복사 -> 복사 의 비용 절약
	for (int i = 1; i < ac; i++) {
		std::stringstream nums_stream(av[i]);
		if (nums_stream >> num && nums_stream.eof() && num >= 0) // 자동으로 형변환 되는지?
			nums.push_back(num);
		else {
			std::cout << "Invalid argumet" << std::endl;
			return 1;
		}
	}
	
	print_vector(nums, "Before : ");
	PmergeMe mergeSort(nums);

	return 0;
}