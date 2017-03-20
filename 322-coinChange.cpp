class Solution {

public:

	vector<int> table;

	int coinChange(vector<int> &coins, int amount) {

		if (coins.size() == 0) {
			return -1 * (amount > 0);
		}

		sort(coins.begin(), coins.end());

		table.clear();
		table.resize(amount + 1, INT_MAX);

		table[0] = 0;
		for (int i = 1; i < min(coins[0], amount + 1); ++i) {
			table[i] = -1;
		}

		for (int i = coins[0]; i <= amount; ++i) {
			for (int j = 0; j < coins.size(); ++j) {
				if (i - coins[j] >= 0) {
					if (table[i - coins[j]] != -1) {
						table[i] = min(table[i], 1 + table[i - coins[j]]);
					}
				} else {
					break;
				}
			}
			if (table[i] == INT_MAX) {
				table[i] = -1;
			}
		}

		return table[amount];
	}

};