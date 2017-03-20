class Solution {
public:
	vector<int> plusOne(vector<int> &digits) {
		int i, n = digits.size();
		for (i = n - 1; i >= 0; --i) {
			if (digits[i] == 9) {
				digits[i] = 0;
			} else {
				break;
			}
		}
		if (i == -1) {
			digits.push_back(0);
			digits[0] = 1;
		} else {
			++digits[i];
		}
		return digits;
	}
};