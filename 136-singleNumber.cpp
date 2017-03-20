/*
class Solution {
public:
	int singleNumber(vector<int> &num) {
		unordered_map<int, int> table;
		unordered_map<int, int>::iterator iter;
		for (int i = 0; i < num.size(); ++i) {
			table[num[i]] += 1;
		}
		for (iter = table.begin(); iter != table.end(); ++iter) {
			if (iter->second == 1) {
				return iter->first;
			}
		}
	}
};
*/
class Solution {
public:
	int singleNumber(vector<int> &num) {
		int result = 0;
		for (int i = 0; i < num.size(); ++i) {
			result ^= num[i];
		}
		return result;
	}
};