class Solution {
public:
	bool wordPattern(string pattern, string str) {
		vector<int> sp(1, -1);
		for (int i = 0; i < str.length(); ++i) {
			if (str[i] == ' ') {
				sp.push_back(i);
			}
		}
		if (sp.size() != pattern.length()) {
			return false;
		}
		sp.push_back(str.length());
		unordered_map<char, string> d1;
		unordered_map<string, char> d2;
		for (int i = 0; i < pattern.length(); ++i) {
			char c = pattern[i];
			string substr = str.substr(sp[i] + 1, sp[i + 1] - sp[i] - 1);
			if (d1.find(c) == d1.end()) {
				d1[c] = substr;
			} else {
				if (d1[c].compare(substr) != 0) {
					return false;
				}
			}
			if (d2.find(substr) == d2.end()) {
				d2[substr] = c;
			} else {
				if (d2[substr] != c) {
					return false;
				}
			}
		}
		return true;
	}
};