class Solution {
public:
	vector< vector<int> > result;
	int longestPalindromeSubseq(string &s) {
		result.clear();
		result.resize(s.length(), vector<int>(s.length(), -1));
		return work(s, 0, s.length() - 1);
	}

	int work(string &s, int l, int r) {
		if (l <= r && result[l][r] != -1) {
			return result[l][r];
		}
		if (l > r) {
			return 0;
		}
		if (l == r) {
			result[l][r] = 1;
			return 1;
		}
		if (s[l] == s[r]) {
			result[l][r] = max(result[l][r], 2 + work(s, l + 1, r - 1));
		} else {
			result[l][r] = max(work(s, l + 1, r), work(s, l, r - 1));
		}
		return result[l][r];
	}
};