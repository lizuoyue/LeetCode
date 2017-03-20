class Solution {
public:
	vector<int> list;
	vector< vector<int> > result;
	vector< vector<int> > combine(int n, int k) {
		list.clear();
		result.clear();
		backtracking(n, k);
		return result;
	}

	void backtracking(int n, int k) {
		if (list.size() == k) {
			result.push_back(list);
			return;
		}
		int id = list.size() + 1, upper = id + (n - k);
		int init;
		if (id == 1) {
			init = 1;
		} else {
			init = list.back() + 1;
		}
		for (int i = init; i <= upper; ++i) {
			list.push_back(i);
			backtracking(n, k);
			list.pop_back();
		}
	}
};