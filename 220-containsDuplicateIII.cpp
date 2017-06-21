class Solution {
public:
	bool containsNearbyAlmostDuplicate(vector<int> &num, int k, int t) {
		multiset<long long> window;
		vector<multiset<long long>::iterator> iter(num.size());
		for (int i = 0; i < num.size(); ++i) {
			if (i > k) window.erase(iter[i - k - 1]);
			multiset<long long>::iterator it = window.lower_bound((long long)num[i] - (long long)t);
			if (it != window.end() && *it <= ((long long)num[i] + (long long)t)) return true;
			iter[i] = window.insert(num[i]);
		}
		return false;
	}
};