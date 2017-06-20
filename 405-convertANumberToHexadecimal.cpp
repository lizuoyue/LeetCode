class Solution {
public:
	string toHex(int num) {
		if (num == 0) return "0";
		unordered_map<int, char> table;
		for (int i = 0; i < 10; ++i) {
			table[i] = '0' + i;
		}
		for (int i = 0; i < 6; ++i) {
			table[i + 10] = 'a' + i;
		}
		bool flag = false;
		string result;
		for (int i = 31; i > 0; i -= 4) {
			int key = 0;
			for (int j = 0; j < 4; ++j) {
				key |= ((((1 << (i - j)) & num) != 0) << (3 - j));
			}
			char c = table[key];
			if (flag) {
				result.push_back(c);
			} else {
				if (c != '0') {
					flag = true;
					result.push_back(c);
				}
			}
			
		}
		return result;
	}
};