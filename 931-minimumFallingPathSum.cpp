class Solution {
public:
	int minFallingPathSum(vector< vector<int> > &A) {
		int n = A.size();
		int res = 999999;
		for (int i = n - 2; i >= 0; --i) {
			for (int j = 0; j < n; ++j) {
				int temp = 99999;
				for (int k = -1; k < 2; ++k) {
					if ((j + k) < 0) {
						continue;
					}
					if ((j + k) > n - 1) {
						continue;
					}
					temp = min(temp, A[i + 1][j + k]);
				}
				A[i][j] += temp;
			}
		}
		for (int i = 0; i < n; ++i) {
			res = min(res, A[0][i]);
		}
		return res;
	}
};