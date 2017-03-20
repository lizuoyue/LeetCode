class Solution {
public:
	void merge(vector<int> &num1, int m, vector<int> &num2, int n) {
		vector<int> list;
		int i = 0, j = 0;
		while (i < m && j < n) {
			if (num1[i] < num2[j]) {
				list.push_back(num1[i]);
				++i;
			} else {
				list.push_back(num2[j]);
				++j;
			}
		}
		for (; i < m; ++i) {
			list.push_back(num1[i]);
		}
		for (; j < n; ++j) {
			list.push_back(num2[j]);
		}
		for (int k = 0; k < list.size(); ++k) {
			num1[k] = list[k];
		}
	}
};