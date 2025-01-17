#include "coin_change.h"

#include <algorithm>

int coin_change::coinChange(std::vector<unsigned int> coins, unsigned int amount) {
	if (amount == 0) {
		return 0;
	}

	std::sort(coins.begin(), coins.end(), std::greater<unsigned int>());

	unsigned number_of_coins{0};
	unsigned current_amount{amount};
	for (auto coin : coins) {
		number_of_coins += current_amount / coin;
		current_amount %= coin;
	}
	if (current_amount != 0) {
		return -1;
	}
	return number_of_coins;
}
