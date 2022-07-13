#include "triangle.hpp"
#include "prune_search.hpp"

#include <ostream>

bool operator < (const voidhoge::vec2& a, const voidhoge::vec2& b) {
	auto cosa = a.abs()/a.x;
	auto cosb = b.abs()/b.x;
//	return std::acos(cosa) < std::acos(cosb);
	return cosa < cosb;
}

voidhoge::vec2 voidhoge::triangle::split_k(const std::size_t k) {
	auto split = k_th_smallest(this->points, k);
	return split;
}
