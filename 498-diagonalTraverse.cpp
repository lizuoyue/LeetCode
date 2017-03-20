class Solution {
public:
	int m, n;
	vector<int> result;
	vector<int> findDiagonalOrder(vector< vector<int> > &matrix) {
		result.clear();
		m = matrix.size(); if (m == 0) return result;
		n = matrix[0].size(); if (n == 0) return result;
		int flag = 0;
		for (int i = 0; i < (m + n - 1); ++i) {
			work(matrix, i, flag);
			flag = 1 - flag;
		}
		return result;
	}

	void work(vector< vector<int> > &matrix, int num, int flag) {
		if (flag == 0) {
			for (int i = max(0, num - m + 1); i <= min(num, n - 1); ++i) {
				result.push_back(matrix[num - i][i]);
			}
		}
		if (flag == 1) {
			for (int i = max(0, num - n + 1); i <= min(num, m - 1); ++i) {
				result.push_back(matrix[i][num - i]);
			}
		}
	}
};