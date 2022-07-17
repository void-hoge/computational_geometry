// 27019578
// Mugi Noda

#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <ostream>

std::mt19937 mt(2);

template<typename T>
void print_vec(std::vector<T> vec, std::ostream& ost) {
	// print the single dimention std::vector<T> VEC.
	if (vec.size() != 0) {
		ost << "["<< vec.at(0);
		for (std::size_t i = 1; i < vec.size(); i++) {
			ost << ", " << vec.at(i);
		}
		ost << "]" << std::endl;
	}
}

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
T k_th_smallest(std::vector<T> vec, const std::size_t k, std::size_t left, std::size_t right) {
	// Returns the kth element in ascending order.
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
	return vec.at(k);
}

template<typename T>
T k_th_smallest_sort(std::vector<T> vec, const std::size_t k, std::size_t left, std::size_t right) {
	std::sort(vec.begin()+left, vec.begin()+right);
	return vec.at(k);
}

int main() {
	std::vector<int> vec;
	const std::size_t n = 10000;
	for (std::size_t i = 0; i < n; i++) {
		vec.push_back(i);
	}
	std::shuffle(vec.begin(), vec.end(), mt);
	{
		auto start = std::chrono::system_clock::now();
		for (std::size_t i = 0; i < n; i++) {
			auto tmp = k_th_smallest(vec, i, 0, vec.size());
			if (i != tmp) {
				throw std::runtime_error("k_th_smallest: wrong output");
			}
		}
		auto end = std::chrono::system_clock::now();
		auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end-start).count();
		std::cout << "Prune & Search: " << elapsed << " microseconds" << std::endl;
	}
	{
		auto start = std::chrono::system_clock::now();
		for (std::size_t i = 0; i < n; i++) {
			auto tmp = k_th_smallest_sort(vec, i, 0, vec.size());
			if (i != tmp) {
				throw std::runtime_error("k_th_smallest_sort: wrong output");
			}
		}
		auto end = std::chrono::system_clock::now();
		auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end-start).count();
		std::cout << "std::sort: " << elapsed << " microseconds" << std::endl;
	}
	return 0;
}
