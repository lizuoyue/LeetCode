class Solution {
public:
	int numSquares(int n) {
		int a = int(floor(sqrt(n)));
		vector<int> dp(n + 1, INT_MAX);
		dp[0] = 0;
		for (int i = 1; i <= a; ++i) {
			dp[i * i] = 1;
		}
		for (int i = 2; i <= n; ++i) {
			if (dp[i] == INT_MAX) {
				int b = int(floor(sqrt(i)));
				for (int j = 1; j <= b; ++j) {
					dp[i] = min(dp[i], dp[i - j * j]);
				}
				++dp[i];
			}
		}
		return dp[n];
	}
};