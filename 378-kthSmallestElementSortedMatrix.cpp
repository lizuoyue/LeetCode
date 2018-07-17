class Solution {
public:
	int binarySearch(vector<int> &v, int k) {
		int n = v.size();
		int l = 0, r = n - 1;
		if (k < v[0]) {
			return -1;
		}
		while (l < r) {
			int mid = (l + r + 1) / 2;
			if (v[mid] <= k) {
				l = mid;
			} else {
				r = mid - 1;
			}
		}
		return l;
	}

	int kthSmallest(vector< vector<int> > &matrix, int k) {
		int m = matrix.size(), n = matrix[0].size();
		int l = matrix[0][0], r = matrix[m - 1][n - 1];
		while (l < r) {
			int mid = (l + r) / 2;
			int s = 0;
			for (int i = 0; i < m; ++i) {
				s += binarySearch(matrix[i], mid) + 1;
			}
			if (s >= k) {
				r = mid;
			} else {
				l = mid + 1;
			}
		}
		return l;
	}
};