class Solution {
public:
	int numSubarraysWithSum(vector<int> &A, int S) {
		if (A.size() == 0) {
			return 0;
		}
		unordered_map<int, int> stat;
		unordered_map<int, int>::iterator iter, temp;
		vector<int> sum(A.size() + 1, 0);
		stat[0] = 1;
		for (int i = 1; i <= A.size(); ++i) {
			sum[i] = A[i - 1] + sum[i - 1];
			stat[sum[i]] += 1;
		}
		int res = 0;
		for (iter = stat.begin(); iter != stat.end(); ++iter) {
			int k = iter->first, v = iter->second;
			if (S == 0) {
				res += (v * (v - 1) / 2);
			} else {
				int ks = k + S;
				temp = stat.find(ks);
				if (temp != stat.end()) {
					res += v * temp->second;
				}
			}
		}
		return res;
	}
};