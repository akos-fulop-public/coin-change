#include <gtest/gtest.h>

#include <coin_change.h>

using coin_change::coinChange;

TEST(CoinChange, ZeroAmount) {
	EXPECT_EQ(coinChange(0, 0), 0);
}
