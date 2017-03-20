class Solution {
public:
	int uniquePathsWithObstacles(vector< vector<int> > &table) {
		int m = table.size(), n = table[0].size();
		table[m - 1][n - 1] = !table[m - 1][n - 1];
		for (int i = m - 2; i >= 0; --i) {
			if (table[i][n - 1] == 0) {
				table[i][n - 1] = table[i + 1][n - 1];
			} else {
				table[i][n - 1] = 0;
			}
		}
		for (int j = n - 2; j >= 0; --j) {
			if (table[m - 1][j] == 0) {
				table[m - 1][j] = table[m - 1][j + 1];
			} else {
				table[m - 1][j] = 0;
			}
		}
		for (int i = m - 2; i >= 0; --i) {
			for (int j = n - 2; j >= 0; --j) {
				if (table[i][j] == 0) {
					table[i][j] = table[i + 1][j] + table[i][j + 1];
				} else {
					table[i][j] = 0;
				}
			}
		}
		return table[0][0];
	}
};