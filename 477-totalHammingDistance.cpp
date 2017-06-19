class Solution {
public:
	int totalHammingDistance(vector<int> &num) {
		vector<int> count(32, 0);
		for (int i = 0; i < num.size(); ++i) {
			for (int j = 0; j < 32; ++j) {
				count[j] += ((num[i] & (1 << j)) > 0);
			}
		}
		int result = 0;
		for (int i = 0; i < 32; ++i) {
			result += count[i] * (num.size() - count[i]);
		}
		return result;
	}
};