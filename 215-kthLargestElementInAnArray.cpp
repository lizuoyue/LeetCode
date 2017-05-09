class Solution {
public:
	int work(vector<int> &nums, int k, int l, int r) {
		// cout << l << " " << r << endl;
		assert(k >= 1);
		assert(k <= (r - l + 1));
		if (l == r) {
			return nums[l];
		}
		int a = nums[l];
		int i = l + 1, j = r;
		while (i < j) {
			if (nums[i] > a) {
				int temp = nums[j];
				nums[j] = nums[i];
				nums[i] = temp;
				--j;
			} else {
				++i;
			}
		}
		assert(i == j);
		if (nums[i] > a) {
			--i;
		}
		int temp = nums[i];
		nums[i] = nums[l];
		nums[l] = temp;
		if (i - l + 1 < k) {
			return work(nums, k - (i - l + 1), i + 1, r);
		} else if (i - l + 1 > k) {
			return work(nums, k, l, i - 1);
		} else {
			return nums[i];
		}

	}
	int findKthLargest(vector<int> &nums, int k) {
		return work(nums, nums.size() - k + 1, 0, nums.size() - 1);
	}
};