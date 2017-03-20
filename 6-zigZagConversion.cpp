class Solution {
public:
	string convert(string s, int numRows) {
		if (numRows == 1) {
			return s;
		}
		string result = "";
		int j = 0, period = (numRows - 1) * 2;
		while (j < s.length()) {
			result += s[j];
			j += period;
		}
		for (int i = 1; i < numRows - 1; ++i) {
			j = i;
			int addition = period - i * 2;
			while (j < s.length()) {
				result += s[j];
				j += addition;
				addition = period - addition;
			}
		}
		j = numRows - 1;
		while (j < s.length()) {
			result += s[j];
			j += period;
		}
		return result;
	}
};