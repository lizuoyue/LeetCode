class Solution {
public:
	int minSubArrayLen(int s, vector<int> &nums) {
		int minLen = nums.size();
		if (minLen == 0) {
			return 0;
		}
		int i = 0, j = 0, sum = nums[0];
		while (i <= j && j < nums.size()) {
			if (sum < s) {
				++j;
				if (j < nums.size()) {
					sum += nums[j];
				}
			} else {
				if (i == j) {
					return 1;
				}
				minLen = min(minLen, j - i + 1);
				sum -= nums[i];
				++i;
			}
		}
		if (sum < s && i == 0 && j == nums.size()) {
			return 0;
		}
		return minLen;
	}
};