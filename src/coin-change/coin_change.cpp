#include "coin_change.h"

#include <algorithm>

int failedOrMin(int solution_a, int solution_b) {
	if (solution_a == solution_b == -1) {
		return -1;
	} else if (solution_a == -1) {
		return solution_b;
	} else if (solution_b == -1) {
		return solution_a;
	}
	return std::min(solution_a, solution_b);
}

int recursiveCoinChange(const std::vector<unsigned int>& coins, unsigned int current_coin_index, int remaining_amount) {
	if (remaining_amount == 0) {
		return 0;
	}
	if (remaining_amount < 0) {
		return -1;
	}
	if (current_coin_index >= coins.size()) {
		return -1;
	}
	auto exclude_current_solution = recursiveCoinChange(coins, current_coin_index + 1, remaining_amount);
	auto select_current_solution = recursiveCoinChange(coins, current_coin_index, remaining_amount - coins[current_coin_index]);
	if (select_current_solution != -1) {
		select_current_solution += 1;
	}
	return failedOrMin(exclude_current_solution, select_current_solution);
}

int coin_change::coinChange(std::vector<unsigned int> coins, unsigned int amount) {
	return recursiveCoinChange(coins, 0, amount);
}

void removeOneCoin(std::map<unsigned int, unsigned int>& coins, unsigned int coin_to_remove) {
	auto iterator = coins.find(coin_to_remove);
	iterator->second -= 1;
	if (iterator->second == 0) {
		coins.erase(iterator);
	}
}

int recursiveLimitedCoinChange(std::map<unsigned int, unsigned int> coins, int remaining_amount) {
	if (remaining_amount == 0) {
		return 0;
	}
	if (coins.empty()) {
		return -1;
	}
	auto current_coin = coins.begin()->first;
	int select_current_solution = -1;
	if (current_coin <= remaining_amount) {
		auto coins_select_current{coins};
		removeOneCoin(coins_select_current, current_coin);
		select_current_solution = recursiveLimitedCoinChange(coins_select_current, remaining_amount - current_coin);
		if (select_current_solution != -1) {
			select_current_solution += 1;
		}
	}
	auto coins_exclude_current{coins};
	coins_exclude_current.erase(coins_exclude_current.begin());
	int exclude_current_solution = recursiveLimitedCoinChange(coins_exclude_current, remaining_amount);
	return failedOrMin(exclude_current_solution, select_current_solution);
}

int coin_change::limitedCoinChange(std::map<unsigned int, unsigned int> coins, unsigned int amount) {
	return recursiveLimitedCoinChange(coins, amount);
}
