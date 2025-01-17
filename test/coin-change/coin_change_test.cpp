#include <gtest/gtest.h>

#include <coin_change.h>

using coin_change::coinChange;
using coin_change::limitedCoinChange;

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

TEST(CoinChange, GreedyFail) {
	EXPECT_EQ(coinChange({3, 8, 11}, 20), 4);
}

TEST(LimitedCoinChange, NotEnoughCoins) {
	EXPECT_EQ(limitedCoinChange({{1, 2}}, 3), -1);
}

TEST(LimitedCoinChange, SimpleTwoCoins) {
	EXPECT_EQ(limitedCoinChange({{1, 10},{2, 10}}, 4), 2);
}

TEST(LimitedCoinChange, NeedToBreakDown) {
	EXPECT_EQ(limitedCoinChange({{1, 10},{2, 1}}, 4), 3);
}
