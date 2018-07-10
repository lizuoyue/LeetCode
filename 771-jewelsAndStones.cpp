class Solution {
public:
	int numJewelsInStones(string J, string S) {
		vector<bool> table('z' - 'A' + 1, false);
		for (string::iterator iter = J.begin(); iter < J.end(); ++iter) {
			char c = *iter;
			table[c - 'A'] = true;
		}
		int count = 0;
		for (string::iterator iter = S.begin(); iter < S.end(); ++iter) {
			char c = *iter;
			count += table[c - 'A'];
		}
		return count;
	}
};