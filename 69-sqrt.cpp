class Solution {
public:
	int mySqrt(int x) {
		if (x <= 0) return 0;
		int l = 1, r = int(sqrt(INT_MAX));
		while (l < r) {
			int mid = (l + r + 1) / 2;
			if (mid * mid <= x) {
				l = mid;
			} else {
				r = mid - 1;
			}
		}
		return l;
	}
};