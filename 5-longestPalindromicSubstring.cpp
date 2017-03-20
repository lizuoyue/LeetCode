class Solution {
public:
	vector< vector<bool> > dp;
	string longestPalindrome(string s) {
		dp.clear();
		dp.resize(s.length(), vector<bool>(s.length(), true));
		int maxLen = 1, u = 0;
		for (int i = s.length() - 1; i >= 0; --i) {
			for (int j = i + 1; j < s.length(); ++j) {
				if (s[i] == s[j]) {
					if (i == j + 1) {
						dp[i][j] = true;
					} else {
						dp[i][j] = dp[i + 1][j - 1];
					}
				} else {
					dp[i][j] = false;
				}
				if (dp[i][j] && (j - i + 1) > maxLen) {
					maxLen = (j - i + 1);
					u = i;
				}
			}
		}
		return s.substr(u, maxLen);
	}
};