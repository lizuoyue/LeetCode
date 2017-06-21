class Solution {
public:
	int characterReplacement(string s, int k) {
		if (s == "") return 0;
		if (s.length() == 1) return 1;
		int result = 0;
		vector<int> count(26, 0);
		int begin = 0, max_count = 0;
		for (int end = 0; end < s.length(); ++end) {
			++count[s[end] - 'A'];
			if (count[s[end] - 'A'] > max_count) {
				max_count = count[s[end] - 'A'];
			}
			while (end - begin + 1 - max_count > k) {
				--count[s[begin] - 'A'];
				++begin;
				max_count = 0;
				for (int i = 0; i < 26; ++i) {
					max_count = max(max_count, count[i]);
				}
			}
			result = max(result, end - begin + 1);
		}
		return result;
	}
};
