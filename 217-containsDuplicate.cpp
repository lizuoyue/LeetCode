class Solution {
public:
	bool containsDuplicate(vector<int> &nums) {
		unordered_map<int, int> table;
		unordered_map<int, int>::iterator iter;
		for (int i = 0; i < nums.size(); ++i) {
			iter = table.find(nums[i]);
			if (iter != table.end()) {
				return true;
			} else {
				table[nums[i]] = 0;
			}
		}
		return false;
	}
};