class Solution {
public:
	int maxSubArray(vector<int> &nums) {

		if (nums.size() == 0) {
			return 0;
		}

		int maxVal = -INT_MAX, minSum = 0, sum = 0;
		for (int i = 0; i < nums.size(); ++i) {
			sum += nums[i];
			maxVal = max(maxVal, sum - minSum);
			minSum = min(minSum, sum);
		}

		return maxVal;
	}
};
