class Solution {
public:
	string countAndSay(int n) {
		if (n == 1) {
			return "1";
		}
		string prefix = countAndSay(n - 1);
		string addition;
		int count = 1;
		char obj = prefix[0];
		for (int i = 1; i < prefix.length(); ++i) {
			if (prefix[i] == obj) {
				++count;
			} else {
				addition += to_string(count) + obj;
				count = 1;
				obj = prefix[i];
			}
		}
		addition += to_string(count) + obj;
		return addition;
	}
};