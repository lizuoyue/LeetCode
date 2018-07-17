class Solution {
public:
	int shortestSubarray(vector<int> &a, int k) {
		vector<int> s(a.size() + 1, 0);
		for (int i = 0; i < a.size(); ++i) {
			s[i + 1] = s[i] + a[i];
		}
		int res = INT_MAX;
		deque< pair<int, int> > q;
		q.push_back(make_pair(0, 0));
		for (int i = 1; i < s.size(); ++i) {
			while (!q.empty() && q.back().second >= s[i]) {
				q.pop_back();
			}
			q.push_back(make_pair(i, s[i]));
			while (!q.empty() && q.back().second - q.front().second >= k) {
				res = min(res, q.back().first - q.front().first);
				q.pop_front();
			}
		}
		if (res != INT_MAX) {
			return res;
		} else {
			return -1;
		}
	}
};