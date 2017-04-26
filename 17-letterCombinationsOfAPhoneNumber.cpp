class Solution {
public:

	vector<string> table, result;

	void work(string &digits, int idx, string &str) {
		if (idx == digits.length()) {
			result.push_back(str);
			return;
		}
		string can = table[digits[idx] - '2'];
		for (int i = 0; i < can.length(); ++i) {
			str.push_back(can[i]);
			work(digits, idx + 1, str);
			str.pop_back();
		}
	}

	vector<string> letterCombinations(string digits) {

		result.clear();
		if (digits.length() == 0) {
			return result;
		}

		for (int i = 0; i < digits.size(); ++i) {
			if (!(digits[i] >= '2' && digits[i] <= '9')) {
				return result;
			}
		}
		
		table.clear();
		table.resize(8);
		table[0] = "abc";
		table[1] = "def";
		table[2] = "ghi";
		table[3] = "jkl";
		table[4] = "mno";
		table[5] = "pqrs";
		table[6] = "tuv";
		table[7] = "wxyz";

		string str;
		work(digits, 0, str);
		return result;
	}
};