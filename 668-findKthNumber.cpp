class Solution {
public:
	int findKthNumber(int m, int n, int k) {
		int mm = min(m, n), nn = max(m, n);
		int l = 1, r = mm * nn;
		while (l < r) {
			int mid = (l + r) / 2;
			int s = 0;
			for (int i = 1; i <= m; ++i) {
				s += min(mid / i, n);
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