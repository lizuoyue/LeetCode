class Solution {
public:
	bool find132pattern(vector<int> &num) {
		if (num.size() < 3) return false;
		vector<int> leftMin(num.size(), INT_MAX);
		leftMin[1] = num[0];
		for (int i = 2; i < num.size(); ++i) {
			leftMin[i] = min(leftMin[i - 1], num[i - 1]);
		}
		set<int, greater<int> > table;
		vector<int> rightMax(num.size(), INT_MIN);
		table.insert(INT_MIN);
		for (int i = num.size() - 1; i >= 0; --i) {
			set<int>::iterator iter = table.upper_bound(num[i]);
			rightMax[i] = *iter;
			table.insert(num[i]);
		}
		for (int i = 1; i < (num.size() - 1); ++i) {
			if (rightMax[i] > leftMin[i]) {
				return true;
			}
		}
		return false;
	}
};
