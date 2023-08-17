#include "PmergeMe.hpp"

bool cmp_func(const std::pair<int, int>& a, const std::pair<int, int>& b)
{
	return (a.second < b.second);
}

void get_time(struct timeval start_time, struct timeval end_time, bool is_vec) {
	long long milli, second, micro;
    
    second = end_time.tv_sec - start_time.tv_sec;
    micro = end_time.tv_usec - start_time.tv_usec; 
    milli = ((second) * 1000000 + micro * 1.0);
	if (is_vec)
		std::cout << "vector_";
	else
		std::cout << "deque_"; //벡터면 vecotr_ 덱이면 deque_출력
	if (milli > 999 )
		std::cout << "time : " << milli / 1000 << "." << milli % 1000 << "ms" << std::endl; //milli 가 사실은 마이크로 라서 1000보다 크면 1000을 나눠서 밀리로 출력
	else
		std::cout << "time : " << milli << "us" << std::endl;
    // return milli;
}


PmergeMe::PmergeMe(std::vector<int> nums) {

	
	
	{ //vector 시작
		struct timeval vec_start, vec_end;
		bool odd_num = false;
		int last_num;

		gettimeofday(&vec_start, NULL);

		std::vector<int> vec_nums(nums.begin(), nums.end());
		std::vector<std::pair<int, int> > pair_num;

		if (vec_nums.size() % 2) { //홀수 체크
			odd_num = true;
			last_num = nums.back();   // 라스트 넘에 저장
			vec_nums.pop_back();
		}
		for (unsigned int i = 0; i < vec_nums.size(); i +=2) {			// pair을 지어주기 때문에 인덱스 2씩 증가
			std::pair<int, int> tmp1(vec_nums[i], vec_nums[i + 1]); 	// 페어만들기
			if (tmp1.first > tmp1.second)								// pair.first =  작은 수, pair.second = 큰 수
				std::swap(tmp1.first, tmp1.second);
			pair_num.push_back(tmp1);									//pair vector에 추가
		}
		merge_sort(pair_num.begin(), pair_num.end());					//pair vector의 second(큰값) 정렬
		std::vector<int> sorted;		//큰값들 (정렬 됨) <- 메인체인
		std::vector<int> pending;		//나머지값
		for (std::vector<std::pair<int, int> >::iterator it = pair_num.begin(); it != pair_num.end(); it++) {
			sorted.push_back(it->second);	//큰 값들은 이미 정렬 되었으므로  sorted에 넣기
			pending.push_back(it->first);	// 작은 값들은 정렬이 아직 안됨.
		}
		if (odd_num)
			pending.push_back(last_num);	// 홀수여서 따로 뺴놓은 값도 나머지값에 추가

		std::vector<unsigned int> tmp2;
		for (unsigned int i = 0; i < sorted.size(); i++)
			tmp2.push_back(i);				//순서 벡터를 하나 더 만듬.
		
		std::vector<unsigned int> jacob_arr = vec_jacob_create(pending.size()); // 나머지값들의 넣을 순서를 정하는 배열 1, 3, 2, 5, 4, 11, 10, 9, 8, 7, 6, 21, 20...

		for (std::vector<unsigned int>:: iterator b_it = jacob_arr.begin(); b_it != jacob_arr.end(); b_it++) {
			std::vector<int>::iterator s_begin = sorted.begin();
			std::vector<int>::iterator s_end;
			if (*b_it < tmp2.size())
				s_end = sorted.begin() + tmp2[*b_it];
			else
				s_end = sorted.end();
			int insert = pending[*b_it];
			unsigned int insert_idx = binary_search(sorted, s_begin, s_end, insert);
			sorted.insert(sorted.begin() + insert_idx, insert);
			for (std::vector<unsigned int>::iterator it = tmp2.begin(); it != tmp2.end(); it++) {
				if (*it >= insert_idx)
					(*it) += 1;
			}
		}

		_vec_nums = sorted;

		gettimeofday(&vec_end, NULL);
		// long vec_time = get_time(vec_start, vec_end);
		print_vector(_vec_nums, "vector : ");
		get_time(vec_start, vec_end, 1);

		
	}  //vector 끝
	
	{ //deque 시작
		bool odd_num = false;
		int last_num;
		struct timeval deq_start, deq_end;
		
		gettimeofday(&deq_start, NULL);

		std::deque<int>	deq_nums(nums.begin(), nums.end());
		std::deque<std::pair<int, int> > pair_num;

		if (deq_nums.size() % 2) { //홀수 체크
			odd_num = true;
			last_num = nums.back();
			deq_nums.pop_back();
		}
		for (unsigned int i = 0; i < deq_nums.size(); i +=2) {
			std::pair<int, int> tmp(deq_nums[i], deq_nums[i + 1]);
			if (tmp.first > tmp.second)
				std::swap(tmp.first, tmp.second);
			pair_num.push_back(tmp);
		}
		::merge_sort(pair_num.begin(), pair_num.end());
		std::deque<int> sorted;
		std::deque<int> pending;
		for (std::deque<std::pair<int, int> >::iterator it = pair_num.begin(); it != pair_num.end(); it++) {
			sorted.push_back(it->second);
			pending.push_back(it->first);
		}
		if (odd_num)
			pending.push_back(last_num);
		std::deque<unsigned int> tmp2;
		for (unsigned int i = 0; i < sorted.size(); i++)
			tmp2.push_back(i);
		
		std::deque<unsigned int> jacob_arr = deq_jacob_create(pending.size());

			for (std::deque<unsigned int>:: iterator b_it = jacob_arr.begin(); b_it != jacob_arr.end(); b_it++) {
			std::deque<int>::iterator s_begin = sorted.begin();
			std::deque<int>::iterator s_end;
			if (*b_it < tmp2.size())
				s_end = sorted.begin() + tmp2[*b_it];
			else
				s_end = sorted.end();
			int insert = pending[*b_it];
			unsigned int insert_idx = binary_search(sorted, s_begin, s_end, insert);
			sorted.insert(sorted.begin() + insert_idx, insert);
			for (std::deque<unsigned int>::iterator it = tmp2.begin(); it != tmp2.end(); it++) {
				if (*it >= insert_idx)
					(*it) += 1;
			}
		}
		_deq_nums = sorted;


		gettimeofday(&deq_end, NULL);
		// long vec_time = get_time(vec_start, vec_end);
		print_vector(_vec_nums, "deque : ");
		get_time(deq_start, deq_end, 0);
	} //deque 끝



}

unsigned int jacob(unsigned int num) {
	if (num == 0)
		return 0;
	else if (num == 1)
		return 1;
	return (jacob(num - 1) + 2 * jacob(num - 2));
}

std::vector<unsigned int> vec_jacob_create(unsigned int len) {
	std::vector<unsigned int> tmp;
	for (unsigned int i = 0; i <= len; i++) { // 자콥스탈의 수
		unsigned int num = jacob(i); // 0, 1, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461...
		if (num >= len)	
			break;
		tmp.push_back(num);
	}
	tmp.push_back(len);

	std::vector<unsigned int> arr;
	for (unsigned int i = 1; i < tmp.size(); i++) {
		for (unsigned int j = tmp[i]; j > tmp[i - 1]; j--) { //1, 3, 2, 5, 4, 11, 10, 9, 8, 7, 6, 21, 20...
			arr.push_back(j - 1);
		}
	}
	return arr;
}

std::deque<unsigned int> deq_jacob_create(unsigned int len) {
	std::deque<unsigned int> tmp;
	for (unsigned int i = 0; i <= len; i++) {
		unsigned int num = jacob(i);
		if (num >= len)
			break;
		tmp.push_back(num);
	}
	tmp.push_back(len);

	std::deque<unsigned int> arr;
	for (unsigned int i = 1; i < tmp.size(); i++) {
		for (unsigned int j = tmp[i]; j > tmp[i - 1]; j--) {
			arr.push_back(j - 1);
		}
	}
	return arr;
}

void print_vector(std::vector<int> nums, std::string str) {
	std::cout << str << std::endl;
	for (unsigned int i = 0; i < nums.size(); i++)
		std::cout << nums[i] << " ";
	std::cout << std::endl;
}