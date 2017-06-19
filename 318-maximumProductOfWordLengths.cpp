class Solution {
public:
	int maxProduct(vector<string> &word) {
		vector<int> bit(word.size(), 0);
		for (int i = 0; i < word.size(); ++i) {
			for (int j = 0; j < word[i].length(); ++j) {
				bit[i] |= (1 << (word[i][j] - 'a'));
			}
		}
		int result = 0;
		for (int i = 0; i < word.size(); ++i) {
			for (int j = i + 1; j < word.size(); ++j) {
				if ((bit[i] & bit[j]) == 0) {
					int pro = word[i].length() * word[j].length();
					result = max(result, pro);
				}
			}
		}
		return result;
	}
};