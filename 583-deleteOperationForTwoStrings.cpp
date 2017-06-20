class Solution {
public:
	vector< vector<int> > table;
	int minDistance(string word1, string word2) {
		int m = word1.length(), n = word2.length();
		table.clear(); table.resize(m + 1, vector<int>(n + 1, INT_MAX));
		table[0][0] = 0;
		for (int i = 1; i <= m; ++i) {
			table[i][0] = i;
		}
		for (int j = 1; j <= n; ++j) {
			table[0][j] = j;
		}
		for (int i = 1; i <= m; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (word1[i - 1] == word2[j - 1]) {
					table[i][j] = table[i - 1][j - 1];
				} else {
					table[i][j] = min(table[i][j], 1 + table[i - 1][j]);
					table[i][j] = min(table[i][j], 1 + table[i][j - 1]);
				}
			}
		}
		return table[m][n];
	}
};