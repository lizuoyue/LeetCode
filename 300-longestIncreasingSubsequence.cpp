class Solution {
public:
	int lengthOfLIS(vector<int> &nums) {
		vector<int> result;
		vector<int>::iterator iter;
		for (int i = 0; i < nums.size(); ++i) {
			iter = std::lower_bound(result.begin(), result.end(), nums[i]);
			if (iter == result.end()) {
				result.push_back(nums[i]);
			} else {
				*iter = nums[i];
			}
		}
		return result.size();
	}
};