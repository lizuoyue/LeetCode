class Solution {
public:
	int rob(vector<int> &num) {
		int n = num.size();
		if (n == 0) {
			return 0;
		}
		if (n == 1) {
			return num[0];
		}
		if (n == 2) {
			return max(num[0], num[1]);
		}
		if (n == 3) {
		    return max(max(num[0], num[1]), num[2]);
		}
		vector<int> tableA(n), tableB(n - 1);
		tableA[n - 1] = num[n - 1];
		tableA[n - 2] = max(num[n - 2], num[n - 1]);
		for (int i = n - 3; i >= 0; --i) {
			tableA[i] = max(num[i] + tableA[i + 2], tableA[i + 1]);
		}
		tableB[n - 2] = num[n - 2];
		tableB[n - 3] = max(num[n - 3], num[n - 2]);
		for (int i = n - 4; i >= 0; --i) {
			tableB[i] = max(num[i] + tableB[i + 2], tableB[i + 1]);
		}
		return max(tableA[1], num[0] + tableB[2]);
	}
};