class Solution {
public:

	vector< vector<int> > result;

	void work(vector<int> &num, int target, int idx, vector<int> &path, int sum) {
		if (sum == target) {
			result.push_back(path);
		}
		if (sum > target) {
			return;
		}
		for (int i = idx; i < num.size(); ++i) {
			path.push_back(num[i]);
			sum += num[i];
			work(num, target, i + 1, path, sum);
			sum -= num[i];
			path.pop_back();
		}
	}

	vector< vector<int> > combinationSum2(vector<int> &num, int target) {

		result.clear();
		sort(num.begin(), num.end());

		int sum = 0;
		vector<int> path;
		work(num, target, 0, path, sum);

		set< vector<int> > unique;
		for (int i = 0; i < result.size(); ++i) {
			unique.insert(result[i]);
		}
		result.clear();
		for (set< vector<int> >::iterator iter = unique.begin(); iter != unique.end(); ++iter) {
			result.push_back(*iter);
		}
		return result;

	}
};