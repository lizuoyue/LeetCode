class Solution {
public:
	vector< vector<int> > subsets(vector<int> &num) {
		int n = num.size(), N = 1 << n;
		vector< vector<int> > result(N);
		for (int s = 0; s < N; ++s) {
			for (int i = 0; i < n; ++i) {
				if (s & (1 << i)) {
					result[s].push_back(num[i]);
				}
			}
		}
		return result;
	}
};