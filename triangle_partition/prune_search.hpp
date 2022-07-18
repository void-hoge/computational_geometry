// 27019578
// Mugi Noda
#pragma once

#include <iostream>
#include <ostream>
#include <vector>
#include <algorithm>

template<typename T>
std::ostream& print_vec(const std::vector<T>& vec, std::ostream& ost);

template<typename T>
std::ostream& operator << (std::ostream& ost, const std::vector<T>& vec) {
	print_vec(vec, ost);
	return ost;
}

template<typename T>
std::ostream& print_vec(const std::vector<T>& vec, std::ostream& ost) {
	if (vec.size() != 0) {
		ost << "["<< vec.at(0);
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
	// The pivot is the leftmost element.
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
std::vector<T> k_th_smallest(std::vector<T> vec, const std::size_t k, std::size_t left, std::size_t right) {
	// Returns a vector with the k th elements on the left in ascending order.
	const auto left_ = left;
	while (left != right) {
		auto tmp = partition(vec, left, right);
		if (tmp > k+left_) {
			right = tmp;
		} else if (tmp < k+left_) {
			left = tmp+1;
		}else {
			break;
		}
	}
	return vec;
}

// just for benchmark.
template<typename T>
T k_th_smallest_sort(std::vector<T> vec, const std::size_t k) {
	// Returns the kth element in ascending order via std::sort.
	std::sort(vec.begin(), vec.end());
	return vec.at(k);
}

} // namespace voidhoge
