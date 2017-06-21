class Solution {
public:
	int findPeakElement(vector<int> &num) {
		if (num.size() == 1) return 0;
		if (num[0] > num[1]) return 0;
		if (num.back() > num[num.size() - 2]) return num.size() - 1;
		int l = 0, r = num.size() - 1;
		while (l < r) {
			int mid = (l + r) / 2;
			if (num[mid] > num[mid + 1] && num[mid] > num[mid - 1]) {
				return mid;
			} else {
				if (num[mid] < num[mid + 1]) {
					l = mid;
					continue;
				}
				if (num[mid] < num[mid - 1]) {
					r = mid;
				}
			}
		}
		return l;
	}
};