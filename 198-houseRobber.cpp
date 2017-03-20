class Solution {
public:
	int rob(vector<int> &num) {
		int n = num.size();
		if (n == 0) {
			return 0;
		}
		if (n == 1) {
			return num[0];
		}
		if (n == 2) {
			return max(num[0], num[1]);
		}
		vector<int> result(n);
		result[n - 1] = num[n - 1];
		result[n - 2] = max(num[n - 1], num[n - 2]);
		for (int i = n - 3; i >= 0; --i) {
			result[i] = max(num[i] + result[i + 2], result[i + 1]);
		}
		return result[0];
	}
};