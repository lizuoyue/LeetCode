class Solution {
public:
	int arrangeCoins(int n) {
		if (n <= 0) return 0;
		int result = (-1 + sqrt(1 + 8 * double(n))) / 2;
		return result;
	}
};
