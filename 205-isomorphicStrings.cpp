class Solution {
public:
	bool isIsomorphic(string s, string t) {
		vector<int> mapRule1(256, -1), mapRule2(256, -1);
		for (int i = 0; i < s.length(); ++i) {
			if (mapRule1[s[i]] == -1) {
				mapRule1[s[i]] = t[i];
			} else {
				if (mapRule1[s[i]] != t[i]) {
					return false;
				}
			}
			if (mapRule2[t[i]] == -1) {
				mapRule2[t[i]] = s[i];
			} else {
				if (mapRule2[t[i]] != s[i]) {
					return false;
				}
			}
		}
		return true;
	}
};