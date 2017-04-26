class Solution {
public:

	vector< vector<int> > result;

	void generateCombinations(int n, int p, vector< vector<int> > &comb) {

		vector<bool> v(n);
		fill(v.end() - p, v.end(), true);

		do {
			vector<int> single;
			for (int i = 0; i < n; ++i) {
				if (v[i]) {
					single.push_back(i);
				}
			}
			comb.push_back(single);
		} while (next_permutation(v.begin(), v.end()));

	}

	vector< vector<int> > combinationSum3(int k, int n) {

		result.clear();
		vector<int> num;
		for (int i = 1; i < 10; ++i) {
			num.push_back(i);
		}

		vector< vector<int> > comb;
		generateCombinations(9, k, comb);

		for (int i = 0; i < comb.size(); ++i) {
			int sum = 0;
			vector<int> path;
			for (int j = 0; j < comb[i].size(); ++j) {
				sum += num[comb[i][j]];
				path.push_back(num[comb[i][j]]);
			}
			if (sum == n) {
				result.push_back(path);
			}
		}
		return result;

	}
};