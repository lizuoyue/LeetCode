class Solution {
public:
	int rangeBitwiseAnd(int m, int n) {
		if (m < n) {
			return rangeBitwiseAnd(m >> 1, n >> 1) << 1;
		} else {
			return m;
		}
	}
};