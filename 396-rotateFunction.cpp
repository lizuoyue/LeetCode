class Solution {
public:
	int maxRotateFunction(vector<int> &A) {
		if (A.size() == 0) {
			return 0;
		}
		int func = 0, sum = 0, n = A.size();
		for (int i = 0; i < n; ++i) {
			sum += A[i];
			func += i * A[i];
		}
		int maxVal = func;
		for (int i = n - 1; i >= 0; --i) {
			func = func - A[i] * n + sum;
			maxVal = max(maxVal, func);
		}
		return maxVal;
	}
};