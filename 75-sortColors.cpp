class Solution {
public:
	void sortColors(vector<int> &num) {
		vector<int> count(3, 0);
		for (int i = 0; i < num.size(); ++i) {
			++count[num[i]];
		}
		for (int i = 0; i < count[0]; ++i) {
			num[i] = 0;
		}
		for (int i = 0; i < count[1]; ++i) {
			num[count[0] + i] = 1;
		}
		for (int i = 0; i < count[2]; ++i) {
			num[num.size() - 1 - i] = 2;
		}
	}
};