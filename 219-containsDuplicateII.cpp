class Solution {
public:
	bool containsNearbyDuplicate(vector<int> &nums, int k) {
		unordered_map<int, int> table;
		unordered_map<int, int>::iterator iter;
		for (int i = 0; i < nums.size(); ++i) {
			iter = table.find(nums[i]);
			if (iter == table.end()) {
				table[nums[i]] = i;
			} else {
				if (i - iter->second > k) {
					table[nums[i]] = i;
				} else {
					return true;
				}
			}
		}
		return false;
	}
};