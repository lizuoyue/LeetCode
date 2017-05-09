class Solution {
public:
	vector<int> topKFrequent(vector<int> &nums, int k) {
		unordered_map<int, int> table;
		unordered_map<int, int>::iterator iter;
		for (int i = 0; i < nums.size(); ++i) {
			++table[nums[i]];
		}
		vector<int> result;
		if (table.size() < k) {
			return result;
		}
		vector< pair<int, int> > list;
		for (iter = table.begin(); iter != table.end(); ++iter) {
			list.push_back(make_pair(iter->second, iter->first));
		}
		sort(list.begin(), list.end());
		for (int i = 0; i < k; ++i) {
			result.push_back(list[list.size() - i - 1].second);
		}
		return result;
	}
};