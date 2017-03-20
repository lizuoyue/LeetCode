class Solution {
public:
	vector<int> nextGreaterElement(vector<int> &findNums,
		vector<int> &nums) {

		vector<int> result;
		if (nums.size() == 0 || findNums.size() == 0) {
			return result;
		}

		vector<int> stacks;
		stacks.push_back(nums[0]);
		unordered_map<int, int> table;

		for (int i = 1; i < nums.size(); ++i) {
			while (stacks.size() > 0 && nums[i] > stacks.back()) {
				table[stacks.back()] = nums[i];
				stacks.pop_back();
			}
			stacks.push_back(nums[i]);
		}

		for (int i = 0; i < stacks.size(); ++i) {
			table[stacks[i]] = -1;
		}

		for (int i = 0; i < findNums.size(); ++i) {
			result.push_back(table[findNums[i]]);
		}
		return result;

	}
};