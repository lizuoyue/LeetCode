class Solution {
public:
	vector<int> twoSum(vector<int> &numbers, int target) {
		vector<int> result;
		if (numbers.size() < 2) {
			return result;
		}
		unordered_map<int, int> table;
		unordered_map<int, int>::iterator iter;
		table[target - numbers[0]] = 0;
		for (int i = 1; i < numbers.size(); ++i) {
			iter = table.find(numbers[i]);
			if (iter != table.end()) {
				result.resize(2);
				result[0] = iter->second + 1;
				result[1] = i + 1;
				return result;
			} else {
				table[target - numbers[i]] = i;
			}
		}
		return result;
	}
};