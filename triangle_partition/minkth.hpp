#ifndef MIN_KTH_HPP
#define MIN_KTH_HPP

#include <iostream>
#include <ostream>
#include <vector>

template<typename T>
std::ostream& print_vec(const std::vector<T>& vec, std::ostream& ost = std::cout);

template<typename T>
std::ostream& operator << (std::ostream& ost, const std::vector<T>& vec) {
	print_vec(vec, ost);
	return ost;
}

template<typename T>
std::ostream& print_vec(const std::vector<T>& vec, std::ostream& ost) {
	if (vec.size() != 0) {
		std::cout << "["<< vec.at(0);
		for (std::size_t i = 1; i < vec.size(); i++) {
			ost << ", " << vec.at(i);
		}
		ost << "]";
	}
	return ost;
}

namespace voidhoge{

template<typename T>
std::size_t partition(std::vector<T>& vec, const std::size_t left, const std::size_t right) {
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

template<typename T>
int min_kth(std::vector<T> vec, const std::size_t k) {
	// Returns the kth element in ascending order.
	std::size_t left = 0, right = vec.size();
	while (left != right) {
		auto tmp = partition(vec, left, right);
		if (tmp > k) {
			right--;
		} else if (tmp < k) {
			left = tmp+1;
		}else {
			break;
		}
	}
	return vec.at(k);
}

template<typename T>
int min_kth_sort(std::vector<T> vec, const std::size_t k) {
	std::sort(vec.begin(), vec.end());
	return vec.at(k);
}

} // namespace voidhoge

#endif // MIN_KTH_HPP
