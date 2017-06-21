class Solution {
public:
	vector< vector<int> > fourSum(vector<int> &num, int target) {
		sort(num.begin(), num.end());
		vector< vector<int> > result;
		for (int i = 0; i < num.size(); ++i) {
			if (i > 0 && num[i] == num[i - 1]) {
				continue;
			}
			for (int j = i + 1; j < num.size(); ++j) {
				if (j > i + 1 && num[j] == num[j - 1]) {
					continue;
				}
				int tar = target - num[i] - num[j];
				int k = j + 1, l = num.size() - 1;
				while (k < l) {
					int sum = num[k] + num[l];
					if (sum < tar) {
						++k;
					} else if (sum > tar) {
						--l;
					} else {
						vector<int> four(4);
						four[0] = num[i];
						four[1] = num[j];
						four[2] = num[k];
						four[3] = num[l];
						result.push_back(four);
						while (k < l && num[k] == four[2]) ++k;
						while (k < l && num[l] == four[3]) --l;
					}
				}
			}
		}
		return result;
	}
};
