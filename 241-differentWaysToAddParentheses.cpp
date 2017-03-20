class Solution {

public:
	vector<int> nums;
	vector<char> operations;

	vector<int> diffWaysToCompute(string input) {
		nums.clear();
		operations.clear();
		vector<int> result;
		string num = "";
		for (int i = 0; i < input.length(); ++i) {
			if (input[i] >= '0' && input[i] <= '9') {
				num = num + input[i];
			} else {
				nums.push_back(stoi(num));
				num = "";
				operations.push_back(input[i]);
			}
		}
		nums.push_back(stoi(num));
		if (operations.size() == 0) {
			result.push_back(nums[0]);
		}
		for (int i = 0; i < operations.size(); ++i) {
			vector<int> left = work(0, i);
			vector<int> right = work(i + 1, nums.size() - 1);
			for (int j = 0; j < left.size(); ++j) {
				for (int k = 0; k < right.size(); ++k) {
					if (operations[i] == '+') {
						result.push_back(left[j] + right[k]);
					}
					if (operations[i] == '-') {
						result.push_back(left[j] - right[k]);
					}
					if (operations[i] == '*') {
						result.push_back(left[j] * right[k]);
					}
				}
			}
		}
		return result;
	}

	vector<int> work(int l, int r) {
		//nums l ... r
		//operations l ... r - 1
		vector<int> result;
		if (l == r) {
			result.push_back(nums[l]);
		}
		for (int i = l; i < r; ++i) {
			vector<int> left = work(l, i);
			vector<int> right = work(i + 1, r);
			for (int j = 0; j < left.size(); ++j) {
				for (int k = 0; k < right.size(); ++k) {
					if (operations[i] == '+') {
						result.push_back(left[j] + right[k]);
					}
					if (operations[i] == '-') {
						result.push_back(left[j] - right[k]);
					}
					if (operations[i] == '*') {
						result.push_back(left[j] * right[k]);
					}
				}
			}
		}
		return result;
	}
};