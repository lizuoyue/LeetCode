class Solution {
public:
	int removeElement(vector<int> &num, int val) {
		int j = 0;
		for (int i = 0; i < num.size(); ++i) {
			if (num[i] != val) {
				num[j] = num[i];
				++j;
			}
		}
		int n = num.size();
		for (int i = 0; i < (n - j); ++i) {
			num.pop_back();
		}
		return num.size();
	}
};