class Solution {
public:

	vector< vector<int> > tableA, tableB;

	int findMaxForm(vector<string> &str, int m, int n) {
		tableA.clear();
		tableB.clear();
		tableA.resize(m + 1, vector<int>(n + 1));
		tableB.resize(m + 1, vector<int>(n + 1));
		for (int i = 0; i <= m; ++i) {
			for (int j = 0; j <= n; ++j) {
				tableA[i][j] = 0;
			}
		}
		for (int k = 0; k < str.size(); ++k) {
			int a = 0, b = 0;
			for (int i = 0; i < str[k].length(); ++i) {
				a += (str[k][i] == '0');
				b += (str[k][i] == '1');
			}
			for (int i = 0; i <= m; ++i) {
				for (int j = 0; j <= n; ++j) {
					if (a <= i && b <= j) {
						tableB[i][j] = max(tableA[i - a][j - b] + 1, tableA[i][j]);
					} else {
						tableB[i][j] = tableA[i][j];
					}
				}
			}
			tableA = tableB;
		}
		return tableA[m][n];
	}

};