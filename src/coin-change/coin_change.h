#pragma once

#include <vector>
#include <map>

namespace coin_change {

int coinChange(const std::vector<unsigned int> &coins, unsigned int amount);
int limitedCoinChange(const std::map<unsigned int, unsigned int> &coins, unsigned int amount);

} //namespace coin_change
