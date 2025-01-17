#include "coin_change.h"

#include <algorithm>

int recursiveCoinChange(const std::vector<unsigned int>& coins, unsigned int number_of_excluded, int remaining_amount) {
	if (remaining_amount == 0) {
		return 0;
	}
	if (remaining_amount < 0) {
		return -1;
	}
	if (number_of_excluded >= coins.size()) {
		return -1;
	}
	auto exclude_current_solution = recursiveCoinChange(coins, number_of_excluded + 1, remaining_amount);
	auto select_current_solution = recursiveCoinChange(coins, number_of_excluded, remaining_amount - coins[number_of_excluded]);
	if (exclude_current_solution == -1) {
		if (select_current_solution == -1) {
			return -1;
		}
		return select_current_solution + 1;
	} else if (select_current_solution == -1) {
		return exclude_current_solution;
	}
	return std::min(exclude_current_solution, select_current_solution + 1);
}

int coin_change::coinChange(std::vector<unsigned int> coins, unsigned int amount) {
	std::sort(coins.begin(), coins.end(), std::greater<unsigned int>());

	return recursiveCoinChange(coins, 0, amount);
}
