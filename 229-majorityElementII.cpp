class Solution {
public:
	vector<int> majorityElement(vector<int> &nums) {
		vector<int> result;
		if (nums.size() == 0) {
			return result;
		}
		int num1 = -INT_MAX, num2 = -INT_MAX;
		int count1 = 0, count2 = 0;
		for (int i = 0; i < nums.size(); ++i) {
			if (nums[i] == num1) {
				++count1;
				continue;
			}
			if (nums[i] == num2) {
				++count2;
				continue;
			}
			if (count1 == 0) {
				num1 = nums[i];
				count1 = 1;
				continue;
			}
			if (count2 == 0) {
				num2 = nums[i];
				count2 = 1;
				continue;
			}
			--count1;
			--count2;
		}

		count1 = 0, count2 = 0;
		for (int i = 0; i < nums.size(); ++i) {
			count1 += (nums[i] == num1);
			count2 += (nums[i] == num2);
		}
		if (count1 > nums.size() / 3) {
			result.push_back(num1);
		}
		if (count2 > nums.size() / 3) {
			result.push_back(num2);
		}
		return result;
	}
};