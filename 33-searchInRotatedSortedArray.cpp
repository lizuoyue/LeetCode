class Solution {
public:
	int search(vector<int> &nums, int target) {
		if (nums.size() == 0) {
			return -1;
		}
		int l = 0, r = nums.size() - 1;
		while (l < r) {
			int mid = (l + r + 1) / 2;
			if (nums[mid] >= nums[0]) {
				l = mid;
			} else {
				r = mid - 1;
			}
		}
		if (l == (nums.size() - 1)) {
			l = 0;
			r = nums.size() - 1;
		} else {
			if (target > nums[l]) {
				return -1;
			} else if (target >= nums[0]) {
				r = l;
				l = 0;
			} else if (target >= nums[l + 1]) {
				l = l + 1;
				r = nums.size() - 1;
			} else {
				return -1;
			}
		}
		while (l < r) {
			int mid = (l + r) / 2;
			if (nums[mid] >= target) {
				r = mid;
			} else {
				l = mid + 1;
			}
		}
		if (nums[l] == target) {
			return l;
		} else {
			return -1;
		}
	}
};