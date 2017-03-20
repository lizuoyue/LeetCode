class Solution {
public:
	vector<int> twoSum(vector<int> &num, int target) {
		vector<int> result(2, -1);
		unordered_map<int, int> presence;
		unordered_map<int, int>::iterator iter;
		for (int i = 0; i < num.size(); ++i) {
			iter = presence.find(num[i]);
			if (iter == presence.end()) {
				presence[target - num[i]] = i;
			} else {
				result[0] = iter->second;
				result[1] = i;
				return result;
			}
		}
		return result;
	}
};