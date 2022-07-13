// 27019578
// Mugi Noda

#include <iostream>
#include <vector>
#include <random>

std::mt19937 mt(2);

template<typename T>
void print_vec(std::vector<T> vec) {
	// print the single dimention std::vector<T> VEC.
	if (vec.size() != 0) {
		std::cout << "["<< vec.at(0);
		for (std::size_t i = 1; i < vec.size(); i++) {
			std::cout << ", " << vec.at(i);
		}
		std::cout << "]" << std::endl;
	}
}

std::size_t partition(std::vector<int>& vec, const std::size_t left, const std::size_t right) {
	// Gather the elements blow pivot on the left side, and returns the index of the pivot after the operation.
	// pivot is the leftmost element.
	auto pivot = vec.at(left);
	std::swap(vec.at(left), vec.at(right-1));
	auto tmp = left;
	for (auto i = left; i < right; i++) {
		if (vec.at(i) < pivot) {
			std::swap(vec.at(tmp), vec.at(i));
			tmp++;
		}
	}
	std::swap(vec.at(right-1), vec.at(tmp));
	return tmp;
}

int min_kth(std::vector<int> vec, const std::size_t k) {
	// Returns the kth element in ascending order.
	std::size_t left = 0, right = vec.size();
	while (left != right) {
		auto tmp = partition(vec, left, right);
		if (tmp > k) {
			right = tmp;
		} else if (tmp < k) {
			left = tmp+1;
		}else {
			break;
		}
	}
	return vec.at(k);
}

int min_kth_sort(std::vector<int> vec, const std::size_t k) {
	std::sort(vec.begin(), vec.end());
	return vec.at(k);
}

int main() {
	std::vector<int> vec;
	for (int i = 0; i < 10000; i++) {
		vec.push_back(i);
	}
	std::shuffle(vec.begin(), vec.end(), mt);
	//print_vec(vec);
	for (std::size_t i = 0; i < 10000; i++) {
		auto tmp = min_kth(vec, i);
		std::cout << i << " " << min_kth(vec, i) << std::endl;
//		std::cout << i << " " << min_kth_sort(vec, i) << std::endl;
		if (i != tmp) {
			break;
		}
	}

	return 0;
}
