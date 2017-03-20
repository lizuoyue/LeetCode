class Solution {
public:
	string findLongestWord(string s, vector<string> &d) {
		int maxLen = 0;
		string result = "";
		for (int i = 0; i < d.size(); ++i) {
			if (canReform(s, d[i])) {
				if (d[i].length() > maxLen) {
					maxLen = d[i].length();
					result = d[i];
				} else if (d[i].length() == maxLen) {
					if (d[i] < result) {
						result = d[i];
					}
				}
			}
		}
		return result;
	}

	bool canReform(string ref, string s) {
		int p = 0;
		for (int i = 0; i < ref.length(); ++i) {
			if (ref[i] == s[p]) {
				++p;
			}
		}
		return p == s.length();
	}
};