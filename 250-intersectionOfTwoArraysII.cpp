class Solution {
public:
	vector<int> intersect(vector<int> &num1, vector<int> &num2) {
		vector<int> result;
		sort(num1.begin(), num1.end());
		sort(num2.begin(), num2.end());
		int i = 0, j = 0;
		while (i < num1.size() && j < num2.size()) {
			if (num1[i] < num2[j]) {
				++i;
			} else if (num1[i] > num2[j]) {
				++j;
			} else {
				result.push_back(num1[i]);
				++i;
				++j;
			}
		}
		return result;
	}
};