class Solution {
public:

	void reverseWords(string &s) {

		int n = s.length();

		vector<int> pos, neg;

		char c = ' ';
		for (int i = 0; i < n; ++i) {
			if (c == ' ' && s[i] != ' ') {
				pos.push_back(i);
			}
			c = s[i];
		}

		s += " ";
		for (int i = 0; i < n; ++i) {
			if (s[i] != ' ' && s[i + 1] == ' ') {
				neg.push_back(i);
			}
		}
		s.pop_back();

		string result;
		for (int i = pos.size() - 1; i >= 0; --i) {
			result += s.substr(pos[i], neg[i] - pos[i] + 1);
			result += " ";
		}

		if (result != "") {
			result.pop_back();
		}
		s = result;

	}
};