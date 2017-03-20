class Solution {
public:
	int findRadius(vector<int> &houses, vector<int> &heaters) {
		int result = 0;
		sort(heaters.begin(), heaters.end());
		for (int i = 0; i < houses.size(); ++i) {
			result = max(result, findNearestHeater(heaters, houses[i]));
		}
		return result;
	}

	int findNearestHeater(vector<int> &heaters, int pos) {
		int l = 0, r = heaters.size() - 1;
		while (l < r) {
			int mid = (l + r) / 2;
			if (heaters[mid] > pos) {
				r = mid;
			} else if (heaters[mid] < pos) {
				l = mid + 1;
			} else {
				return 0;
			}
		}
		if (l > 0) {
			return min(abs(pos - heaters[l - 1]), abs(heaters[l] - pos));
		} else {
			return abs(heaters[l] - pos);
		}
	}
};