// 27019578
// Mugi Noda

#pragma once

#include <iostream>
#include <vector>
#include <random>
#include <cmath>
#include <array>
#include <limits>
#include <ostream>

namespace voidhoge {

class vec2 {
public:
	double x_;
	double y_;
	bool flag_;
	vec2(): x_(0), y_(0), flag_(true) {}

	vec2(double _x, double _y): x_(_x), y_(_y), flag_(true) {}

	vec2(double _x, double _y, bool _flag): x_(_x), y_(_y), flag_(_flag) {}

	double abs() const {
		return std::sqrt(this->x()*this->x()+this->y()*this->y());
	}

	double x() const {
		return this->x_;
	}

	double y() const {
		return this->y_;
	}

	bool flag() const {
		return this->flag_;
	}

	void dump(std::ostream& ost) const{
		ost << this->x() << " " << this->y();
	}

	vec2 rotate(std::size_t r) const{
		auto _x = this->x();
		auto _y = this->y();
		if (r == 1) {
			return vec2(-_x-_y+1, _x, this->flag());
		} else if (r == 2) {
			return vec2(_y, -_x-_y+1, this->flag());
		} else {
			return *this;
		}
	}

	vec2 getline(const vec2 origin) const {
		auto dx = this->x() - origin.x();
		auto dy = this->y() - origin.y();
		if (dx == 0.0f) {
			return vec2(std::numeric_limits<double>::infinity(), 0);
		}else {
			auto a = dy/dx;
			auto b = this->y() - this->x()*a;
			return vec2(a, b);
		}
	}
};

class triangle {
private:
	std::mt19937 mt;
	const std::size_t n;
	std::vector<vec2> points;
	std::array<std::vector<vec2>, 3> solved;
public:
	triangle(const std::vector<vec2> _points): points(_points), n(_points.size()/3) {
		this->mt = std::mt19937(0);
		if ((_points.size()%3) != 0) {
			throw std::runtime_error("The number of input points must be a multiple of 3.");
		}
		for (auto point: _points) {
			auto x = point.x();
			auto y = point.y();
			if (x+y > 1.0f) {
				throw std::runtime_error("The entered point is not in the triangle((0,0), (1,0), (0,1)).");
			}
		}
	}

	void classify_half(std::vector<vec2>& vec, const std::size_t r);
	vec2 classify_three(std::vector<vec2> vec, const std::size_t r);
	bool check_three(const std::vector<vec2> vec, const std::size_t r);
	bool check_all(const vec2 is, const std::vector<vec2>& vec0, const std::vector<vec2>& vec1);
	vec2 solve();

	std::vector<vec2> rotate(std::vector<vec2> vec, const std::size_t left, const std::size_t right, const std::size_t r=0) {
		for (std::size_t i = left; i < right; i++) {
			vec.at(i) = vec.at(i).rotate(r);
		}
		return vec;
	}
};

vec2 getintersection(const vec2 a, const vec2 b);


} // namespace voidhoge

std::ostream& operator << (std::ostream& ost, const voidhoge::vec2& v);

bool operator < (const voidhoge::vec2& a, const voidhoge::vec2& b);

bool operator == (const voidhoge::vec2& a, const voidhoge::vec2& b);
