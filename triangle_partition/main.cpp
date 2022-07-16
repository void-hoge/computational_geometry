#include "triangle.hpp"

#include <iostream>
#include <vector>

int main() {
	std::size_t n;
	std::cin >> n;
	std::cout << n << std::endl;
	std::vector<voidhoge::vec2> points;
	for (std::size_t i = 0; i < n*3; i++) {
		double x, y;
		std::cin >> x >> y;
		auto p = voidhoge::vec2(x, y);
		points.push_back(p);
		std::cout << p << std::endl;
	}
	voidhoge::triangle tmp(points);
	auto result = tmp.solve();
	std::cout << result << std::endl;
	std::cerr << "result: " << result << std::endl;
	return 0;
}
