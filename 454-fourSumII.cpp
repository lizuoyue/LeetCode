class Solution {
public:
	int fourSumCount(vector<int> &A, vector<int> &B,
		vector<int> &C, vector<int> &D) {
		int n = A.size();
		unordered_map<int, int> table;
		unordered_map<int, int>::iterator iter;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				++table[A[i] + B[j]];
			}
		}
		int result = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				iter = table.find(-(C[i] + D[j]));
				if (iter != table.end()) {
					result += iter->second;
				}
			}
		}
		return result;
	}
};