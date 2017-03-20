class Solution {
public:
	int twoSumClosest(vector<int> &num, int begin, int target) {
		int n = num.size();
		if (begin == num.size() - 3) {
			return (num[begin + 1] + num[begin + 2]);
		}
		int minDiff = INT_MAX, lm, rm;
		int l = begin + 1, r = n - 1;
		while (l < r) {
			int temp = abs(num[l] + num[r] - target);
			if (temp < minDiff) {
				lm = l;
				rm = r;
				minDiff = temp;
			}
			if (num[l] + num[r] > target) {
				--r;		
			} else if (num[l] + num[r] < target) {
				++l;
			} else {
				return (num[l] + num[r]);
			}
		}
		return num[lm] + num[rm];
	}

	int threeSumClosest(vector<int> &num, int target) {
		sort(num.begin(), num.end());
		int minDiff = INT_MAX, sum;
		for (int i = 0; i < num.size() - 2; ++i) {
			int temp = num[i] + twoSumClosest(num, i, target - num[i]);
			if (abs(temp - target) < minDiff) {
				sum = temp;
				minDiff = abs(temp - target);
			}
		}
		return sum;
	}
};
