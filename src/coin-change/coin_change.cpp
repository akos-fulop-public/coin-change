#include "coin_change.h"

int coin_change::coinChange(int coins, int amount) {
	if (amount == 0) {
		return 0;
	}
	if (amount % coins != 0) {
		return -1;
	}
	return (amount / coins);
}
