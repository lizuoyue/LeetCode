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
			work(num, target, i, path, sum);
			sum -= num[i];
			path.pop_back();
		}
	}

	vector< vector<int> > combinationSum(vector<int> &num, int target) {

		result.clear();
		sort(num.begin(), num.end());

		int sum = 0;
		vector<int> path;
		work(num, target, 0, path, sum);
		return result;

	}
};