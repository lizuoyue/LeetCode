class Solution {
public:
	vector< vector<int> > result;
	void helper(vector<int> &num, int idx, vector<int> &path) {
		if (idx == num.size()) {
			if (path.size() > 1) {
				result.push_back(path);
			}
			return;
		}
		if (path.size() > 0) {
			if (num[idx] >= path.back()) {
				path.push_back(num[idx]);
				helper(num, idx + 1, path);
				path.pop_back();
			}
			helper(num, idx + 1, path);
		} else {
			path.push_back(num[idx]);
			helper(num, idx + 1, path);
			path.pop_back();
			helper(num, idx + 1, path);
		}
		return;
	}
	vector< vector<int> > findSubsequences(vector<int> &num) {
		result.clear();
		if (num.size() == 1) {
			return result;
		}
		vector<int> path;
		helper(num, 0, path);
		set< vector<int> > res;
		set< vector<int> >::iterator iter;
		for (int i = 0; i < result.size(); ++i) {
			res.insert(result[i]);
		}
		result.clear();
		for (iter = res.begin(); iter != res.end(); ++iter) {
			result.push_back(*iter);
		}
		return result;
	}
};
