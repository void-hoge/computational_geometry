#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include <iostream>
#include <vector>
#include <random>
#include <cmath>

namespace voidhoge {

class vec2 {
public:
	double x;
	double y;
	vec2() {
		this->x = 0;
		this->y = 0;
	}
	vec2(double _x, double _y): x(_x), y(_y) {}
	double abs() const {
		return std::sqrt(x*x+y*y);
	}
};

class triangle {
private:
	std::mt19937 mt;

	std::size_t n;
	std::vector<vec2> points;
public:
	triangle(const std::vector<vec2> _points) {
		this->mt = std::mt19937(0);
		if ((_points.size()%3) != 0) {
			throw std::runtime_error("The number of input points must be a multiple of 3.");
		}
		for (auto point: _points) {
			auto x = point.x;
			auto y = point.y;
			if (x+y > 1.0f) {
				throw std::runtime_error("The entered point is not in the triangle((0,0), (1,0), (0,1)).");
			}
		}
		this->points = _points;
		this->n = _points.size()/3;
	}
	vec2 transform(const vec2 point) {
		auto x = point.x;
		auto y = point.y;
		return vec2(-x-y+1, x);
	}

	vec2 split_k(const std::size_t k);
};

} // namespace voidhoge

#endif // TRIANGLE_HPP
