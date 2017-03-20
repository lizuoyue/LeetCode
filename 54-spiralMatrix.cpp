class Solution {
public:
	int m, n;
	vector<int> result;
	vector<int> spiralOrder(vector< vector<int> > &matrix) {
		result.clear();
		m = matrix.size();
		if (m == 0) return result;
		n = matrix[0].size();
		if (n == 0) return result;
		rf(matrix, 0, 0);
		return result;
	}

	void rf(vector< vector<int> > &matrix, int u, int v) {
		if (m == 0 || n == 0) return;
		for (int i = v; i < (v + n); ++i) {
			result.push_back(matrix[u][i]);
		}
		--m;
		cf(matrix, u + 1, v + n - 1);
	}

	void cf(vector< vector<int> > &matrix, int u, int v) {
		if (m == 0 || n == 0) return;
		for (int i = u; i < (u + m); ++i) {
			result.push_back(matrix[i][v]);
		}
		--n;
		rb(matrix, u + m - 1, v - 1);
	}

	void rb(vector< vector<int> > &matrix, int u, int v) {
		if (m == 0 || n == 0) return;
		for (int i = v; i > (v - n); --i) {
			result.push_back(matrix[u][i]);
		}
		--m;
		cb(matrix, u - 1, v - n + 1);
	}

	void cb(vector< vector<int> > &matrix, int u, int v) {
		if (m == 0 || n == 0) return;
		for (int i = u; i > (u - m); --i) {
			result.push_back(matrix[i][v]);
		}
		--n;
		rf(matrix, u - m + 1, v + 1);
	}
};