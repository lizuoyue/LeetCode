class Solution {
public:
	vector< vector<int> > permuteUnique(vector<int> &nums) {
		vector< vector<int> > result;
		sort(nums.begin(), nums.end());
		result.push_back(nums);
		if (nums[0] == nums.back()) {
			return result;
		}
		int idx;
		for (idx = nums.size() - 1; idx > 0; --idx) {
			if (nums[idx] > nums[idx - 1]) {
				break;
			}
		}
		while (idx > 0) {
			int l = idx, r = nums.size() - 1;
			while (l < r) {
				int mid = (l + r + 1) / 2;
				if (nums[mid] > nums[idx - 1]) {
					l = mid;
				} else {
					r = mid - 1;
				}
			}
			int temp = nums[l];
			nums[l] = nums[idx - 1];
			nums[idx - 1] = temp;
			reverse(nums.begin() + idx, nums.end());
			result.push_back(nums);
			for (idx = nums.size() - 1; idx > 0; --idx) {
				if (nums[idx] > nums[idx - 1]) {
					break;
				}
			}
		}
		return result;
	}
};