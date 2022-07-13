#include "prune_search.hpp"
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
		points.push_back(voidhoge::vec2(x, y));
		std::cout << x << " " << y << std::endl;
	}
	voidhoge::triangle tmp(points);
	std::cerr << (n*3)/2 << std::endl;
	auto split = tmp.split_k((n*3)/2);
	std::cout << split.x << " " << split.y << std::endl;
	return 0;
}
