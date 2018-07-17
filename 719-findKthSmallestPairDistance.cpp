class Solution {
public:
	int binarySearch(vector<int> &v, int idx, int k) {
		int n = v.size();
		int l = idx, r = n - 1;
		if (k < (v[idx] - v[idx - 1])) {
			return 0;
		}
		if (l == r) {
			return (v[l] - v[idx - 1]) <= k;
		}
		while (l < r) {
			int mid = (l + r + 1) / 2;
			if (v[mid] - v[idx - 1] <= k) {
				l = mid;
			} else {
				r = mid - 1;
			}
		}
		return l - idx + 1;
	}

	int smallestDistancePair(vector<int> &nums, int k) {
		sort(nums.begin(), nums.end());
		int n = nums.size();
		int l = 0, r = nums[n - 1] - nums[0];
		while (l < r) {
			int mid = (l + r) / 2;
			int s = 0;
			for (int i = 0; i < n - 1; ++i) {
				s += binarySearch(nums, i + 1, mid);
			}
			if (s >= k) {
				r = mid;
			} else {
				l = mid + 1;
			}
		}
		return l;
	}
};