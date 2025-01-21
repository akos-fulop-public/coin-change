#include <iostream>

#include "coin_change.h"

int main() {
	std::cout << "Solution to simply greedy coin-change problem: " << coin_change::coinChange({3, 8, 11}, 20) << std::endl;
}
