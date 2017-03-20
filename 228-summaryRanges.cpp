class Solution {
public:
	vector<string> summaryRanges(vector<int> &num) {
		string s;
		vector<string> result;
		int l = 0, r = 0;
		for (int i = 0; i < num.size(); ++i) {
			if ((r + 1) < num.size()) {
				if ((num[r + 1] - num[r]) == 1) {
					++r;
				} else {
					if (l == r) {
						s = to_string(num[l]);
					} else {
						s = to_string(num[l]) + "->" + to_string(num[r]);
					}
					++r;
					l = r;
					result.push_back(s);
				}
			} else {
				if (l == r) {
					s = to_string(num[l]);
				} else {
					s = to_string(num[l]) + "->" + to_string(num[r]);
				}
				result.push_back(s);
			}
		}
		return result;
	}
};