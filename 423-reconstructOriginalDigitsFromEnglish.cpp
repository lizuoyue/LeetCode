class Solution {
public:
	string originalDigits(string s) {
		vector<int> count(26, 0);
		for (int i = 0; i < s.length(); ++i) {
			++count[s[i] - 'a'];
		}
		vector<int> dig(10, 0);
		dig[0] = count['z' - 'a'];
		dig[2] = count['w' - 'a'];
		dig[6] = count['x' - 'a'];
		dig[8] = count['g' - 'a'];

		dig[3] = count['h' - 'a'] - dig[8];
		dig[7] = count['s' - 'a'] - dig[6];
		dig[5] = count['v' - 'a'] - dig[7];
		dig[4] = count['f' - 'a'] - dig[5];

		dig[9] = count['i' - 'a'] - dig[5] - dig[6] - dig[8];
		dig[1] = count['n' - 'a'] - dig[7] - dig[9] - dig[9];

		string result;
		for (int i = 0; i < 10; ++i) {
			for (int j = 0; j < dig[i]; ++j) {
				result += ('0' + i);
			}
		}
		return result;
	}
};

// z // zero
// w // two
// x // six
// g // eight

// h - 8 // three
// s - 6 // seven
// v - 7 // five
// f - 5 // four

// i - 5 - 6 - 8 // nine
// n - 7 - 9 - 9 // one
