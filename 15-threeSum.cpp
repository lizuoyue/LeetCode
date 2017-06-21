class Solution {
public:
	vector< vector<int> > threeSum(vector<int> &num) {
		sort(num.begin(), num.end());
		vector< vector<int> > result;
		for (int i = 0; i < num.size(); ++i) {
			if (i > 0 && num[i] == num[i - 1]) {
				continue;
			}
			int target = -num[i];
			int j = i + 1, k = num.size() - 1;
			while (j < k) {
				int sum = num[j] + num[k];
				if (sum < target) {
					++j;
				} else if (sum > target) {
					--k;
				} else {
					vector<int> triple(3);
					triple[0] = num[i];
					triple[1] = num[j];
					triple[2] = num[k];
					result.push_back(triple);
					while (j < k && num[j] == triple[1]) ++j;
					while (j < k && num[k] == triple[2]) --k;
				}
			}
		}
		return result;
	}
};
