#include <iostream>
#include <random>

int Rand() {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distrib(1, 6);
	return distrib(gen);
}

int main() {
	auto a = Rand();
	std::cout << a << '\n';
}
