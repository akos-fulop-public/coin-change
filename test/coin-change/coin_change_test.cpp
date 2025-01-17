#include <gtest/gtest.h>

#include <coin_change.h>

using coin_change::coinChange;

TEST(CoinChange, ZeroAmount) {
	EXPECT_EQ(coinChange({0}, 0), 0);
}

TEST(CoinChange, ExactlyOnce) {
	EXPECT_EQ(coinChange({2}, 2), 1);
}

TEST(CoinChange, Impossible) {
	EXPECT_EQ(coinChange({2}, 3), -1);
}

TEST(CoinChange, Multiple) {
	EXPECT_EQ(coinChange({3}, 12), 4);
}

TEST(CoinChange, SimpleTwoCoins) {
	EXPECT_EQ(coinChange({2, 1}, 3), 2);
}

TEST(CoinChange, UnorderedSimpleTwoCoins) {
	EXPECT_EQ(coinChange({1, 2}, 3), 2);
}
