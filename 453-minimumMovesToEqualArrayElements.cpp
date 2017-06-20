class Solution {
public:
	int minMoves(vector<int> &num) {
		int min_num = INT_MAX;
		for (int i = 0; i < num.size(); ++i) {
			min_num = min(min_num, num[i]);
		}
		int result = 0;
		for (int i = 0; i < num.size(); ++i) {
			result += (num[i] - min_num);
		}
		return result;
	}
};