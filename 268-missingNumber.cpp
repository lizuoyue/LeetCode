class Solution {
public:
	int missingNumber(vector<int> &num) {
		int sum = 0, n = num.size();
		for (int i = 0; i < num.size(); ++i) {
			sum += num[i];
		}
		return n * (n + 1) / 2 - sum;
	}
};