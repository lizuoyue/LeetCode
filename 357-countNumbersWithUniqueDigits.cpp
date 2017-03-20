class Solution {
public:
	int countNumbersWithUniqueDigits(int n) {
		if (n == 0) {
			return 1;
		}
		int product = 9;
		for (int i = 0; i < (n - 1); ++i) {
			product *= (9 - i);
		}
		return product + countNumbersWithUniqueDigits(n - 1);
	}
};