#include <iostream>
#include <algorithm>

long long minimum_split(long long num, long long split) {
	long long unit = num/split;
	long long remain = num%split;
	long long general = split-remain;
	return unit*unit*general + (unit+1)*(unit+1)*remain;
}

long long maximum_split(long long num, long long split) {
	long long num_single = split-1;
	long long remain = num-num_single;
	return num_single + remain*remain;
}

bool func() {
	long long practice, rest;
	std::cin >> practice >> rest;
	if (practice == 0 && rest == 0) {
		return false;
	}
	long long max = LLONG_MIN;
	long long max_split = std::min(rest, practice+1);
	if (rest == 0) {
		std::cout << practice*practice << std::endl;
		return true;
	}
	if (rest == 1) {
		std::cout << practice*practice-1 << std::endl;
		return true;
	}
	if (practice == 0) {
		std::cout << -rest*rest << std::endl;
		return true;
	}
	for (int i = 2; i <= max_split; i++) {
		long long minus = minimum_split(rest, i); // 休み
		long long plus = maximum_split(practice, i-1); // 練習
		long long sum = plus-minus;
		if (sum > max) {
			max = sum;
		}
	}
	std::cout << max << std::endl;
	return true;
}

int main() {
	while (func());
	return 0;
}
