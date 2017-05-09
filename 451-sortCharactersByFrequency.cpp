class Solution {
public:
	string frequencySort(string s) {
		unordered_map<char, int> table;
		unordered_map<char, int>::iterator iter;
		for (int i = 0; i < s.length(); ++i) {
			++table[s[i]];
		}
		vector< pair<int, char> > list;
		for (iter = table.begin(); iter != table.end(); ++iter) {
			list.push_back(make_pair(iter->second, iter->first));
		}
		sort(list.begin(), list.end());
		string result;
		for (int i = int(list.size()) - 1; i >= 0; --i) {
			for (int j = 0; j < list[i].first; ++j) {
				result.push_back(list[i].second);
			}
		}
		return result;
	}
};