class Solution {
public:
	int strStr(string haystack, string needle) {
		if (haystack.length() < needle.length()) return -1;
		if (needle.length() == 0) return 0;
		for (int i = 0; i <= (haystack.length() - needle.length()); ++i) {
			if (haystack[i] == needle[0]) {
				bool flag = true;
				for (int j = 1; j < needle.length(); ++j) {
					if (haystack[i + j] != needle[j]) {
						flag = false;
						break;
					}
				}
				if (flag) {
					return i;
				}
			}
		}
		return -1;
	}
};