#include "minkth.hpp"

#include <iostream>
#include <vector>
#include <random>

std::mt19937 mt(0);

int main() {
	std::vector<int> vec;
	for (int i = 0; i < 10000; i++) {
		vec.push_back(i);
	}
	std::shuffle(vec.begin(), vec.end(), mt);
//	std::cout << vec << std::endl;
	for (std::size_t i = 0; i < 10000; i++) {
		auto tmp = voidhoge::min_kth(vec, i);
//		auto tmp = voidhoge::min_kth_sort(vec, i);
		std::cout << i << " " << tmp << std::endl;
		if (i != tmp) {
			break;
		}
	}
	return 0;
}
