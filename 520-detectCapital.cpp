class Solution {
public:
	bool detectCapitalUse(string word) {
		bool flag1 = word[0] >= 'A' && word[0] <= 'Z';
		bool flag2 = !flag1, flag3 = flag1;
		for (int i = 1; i < word.length(); ++i) {
			bool flag = word[i] >= 'A' && word[i] <= 'Z';
			flag1 = flag1 && flag;
			flag2 = flag2 && !flag;
			flag3 = flag3 && !flag;
		}
		return flag1 || flag2 || flag3;
	}
};