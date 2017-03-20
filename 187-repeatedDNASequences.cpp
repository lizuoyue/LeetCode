class Solution {
public:
	vector<string> findRepeatedDnaSequences(string s) {
		vector<string> result;
		if (s.length() < 10) {
			return result;
		}
		unordered_map<string, int> table;
		for (int i = 0; i <= (s.length() - 10); ++i) {
			table[s.substr(i, 10)] += 1;
		}
		unordered_map<string, int>::iterator iter;
		for (iter = table.begin(); iter != table.end(); ++iter) {
			if (iter->second > 1) {
				result.push_back(iter->first);
			}
		}
		return result;
	}
};