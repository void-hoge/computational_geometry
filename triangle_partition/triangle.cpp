#include "triangle.hpp"
#include "prune_search.hpp"

#include <ostream>

bool operator < (const voidhoge::vec2& a, const voidhoge::vec2& b) {
	auto cosa = a.abs()/a.x();
	auto cosb = b.abs()/b.x();
	return cosa < cosb;
}

bool operator == (const voidhoge::vec2& a, const voidhoge::vec2& b) {
	return a.x() == b.x() && a.y() == b.y();
}

std::ostream& operator << (std::ostream& ost, const voidhoge::vec2& v) {
	v.dump(ost);
	return ost;
}

voidhoge::vec2 voidhoge::getintersection(const vec2 l, const vec2 m) {
	auto a = l.x();
	auto b = l.y();
	auto c = m.x();
	auto d = m.y();
	if (a==c) {
		return vec2(std::numeric_limits<double>::quiet_NaN(), std::numeric_limits<double>::quiet_NaN());
	}else {
		auto x = (d-b)/(a-c);
		auto y = (a*d-b*c)/(a-c);
		return vec2(x, y);
	}
}

void voidhoge::triangle::classify_half(std::vector<voidhoge::vec2>& vec, const std::size_t r) {
	vec = this->rotate(vec, 0, vec.size(), r);
	const auto half = vec.size()/2;
	vec = voidhoge::k_th_smallest(vec, half, 0, vec.size());

	const auto l0 = vec.at(half).getline(vec2(0,0));

	vec = this->rotate(vec, 0, half, 2);
	vec = this->rotate(vec, half, vec.size(), 1);
	const auto k = vec.size()/6-1;
	const auto k_ = vec.size()-half-k-1;
	vec = k_th_smallest(vec, k, 0, half);
	vec = k_th_smallest(vec, k_, half, vec.size());

	const auto l1 = vec.at(k).rotate(1).getline(vec2(1,0));
	const auto l2 = vec.at(half+k_).rotate(2).getline(vec2(0,1));
	const auto is1 = voidhoge::getintersection(l0, l1);
	const auto is2 = voidhoge::getintersection(l0, l2);

	vec = this->rotate(vec, 0, vec.size(), r);
	vec = this->rotate(vec, 0, vec.size(), r);

	vec = this->rotate(vec, 0, half, 1);
	vec = this->rotate(vec, half, vec.size(), 2);

	if (is1.x() < is2.x()) {
		for (std::size_t i = half+k_; i < vec.size(); i++) {
			solved.at(r).push_back(vec.at(i));
			vec.at(i).flag_ = false;
		}
	}else {
		for (std::size_t i = 0; i <= k; i++) {
			solved.at(r).push_back(vec.at(i));
			vec.at(i).flag_ = false;
		}
	}
}

voidhoge::vec2 voidhoge::triangle::classify_three(std::vector<voidhoge::vec2> vec, const std::size_t r) {
	if (vec.size() != 3) {
		return vec2();
	}
	vec = this->rotate(vec, 0, vec.size(), r);
	for (std::size_t i = 0; i < 3; i++) {
		for (std::size_t j = 0; j < 2; j++) {
			if (this->check_three(vec, r)) {
				auto l0 = vec.at(0).getline(vec2(1,0));
				auto l1 = vec.at(1).getline(vec2(0,1));
				auto is = voidhoge::getintersection(l0, l1);
				return is.rotate(r).rotate(r);
			}
			if (j == 0) {
				std::swap(vec.at(1), vec.at(2));
			}
		}
		std::swap(vec.at(0), vec.at(2));
	}

	vec = this->rotate(vec, 0, vec.size(), r);
	vec = this->rotate(vec, 0, vec.size(), r);
	return vec2();
}

bool voidhoge::triangle::check_three(const std::vector<voidhoge::vec2> vec, const std::size_t r) {
	auto p1 = vec.at(0);
	auto p2 = vec.at(1);
	auto p3 = vec.at(2);
	auto l1 = p1.getline(vec2(1,0));
	auto l2 = p2.getline(vec2(0,1));
	auto is = voidhoge::getintersection(l1, l2);
	if (p2.x() > is.x()) {
		return false;
	}
	if (p1.y() > is.y()) {
		return false;
	}
	is = is.rotate(r).rotate(r);
	if (!check_all(is, this->solved.at(2), this->solved.at(1))) {
		return false;
	}
	if (!check_all(is.rotate(1),
				   this->rotate(this->solved.at(0), 0, this->solved.at(0).size(), 1),
				   this->rotate(this->solved.at(2), 0, this->solved.at(2).size(), 1))) {
		return false;
	}

	if (!check_all(is.rotate(2),
				   this->rotate(this->solved.at(1), 0, this->solved.at(0).size(), 2),
				   this->rotate(this->solved.at(0), 0, this->solved.at(1).size(), 2))) {
		return false;
	}
	return true;
}

bool voidhoge::triangle::check_all(const vec2 is, const std::vector<vec2>& vec0, const std::vector<vec2>& vec1) {
	if (vec0.size() != vec1.size()) {
		return false;
	}
	for (std::size_t i = 0; i < vec0.size(); i++) {
		if (vec0.at(i) < is) {
			return false;
		}
		if (is < vec1.at(i)) {
			return false;
		}
	}
	return true;
}

voidhoge::vec2 voidhoge::triangle::solve() {
	while (this->points.size() > 3) {
		for (std::size_t i = 0; i < 3; i++) {
			this->classify_half(this->points, i);
		}
		std::vector<vec2> tmp;
		for (auto p: this->points) {
			if (p.flag()) {
				tmp.push_back(p);
			}
		}
		this->points = tmp;
	}
	for (auto vec: this->solved) {
		std::cout << vec.size() << std::endl;
		for (auto p: vec) {
			std::cout << p << std::endl;
		}
	}
	for (std::size_t i = 0; i < 3; i++) {
		auto result = this->classify_three(this->points, i);
		if (!(result == vec2())) {
			return result;
		}
	}
	return vec2();
}
