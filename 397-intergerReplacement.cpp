class Solution {
public:
	unordered_map<int, int> table;
	unordered_map<int, int>::iterator iter;
	int work(int n) {
		iter = table.find(n);
		if (iter == table.end()) {
			if (n % 2 == 0) {
				table[n] = work(n / 2) + 1;
				// cout << n << ": " << table[n] << endl;
				return table[n];
			} else {
				table[n] = min(work(n - 1), work(n + 1)) + 1;
				// cout << n << ": " << table[n] << endl;
				return table[n];
			}
		} else {
			return iter->second;
		}
	}
	int integerReplacement(int n) {
		table.clear();
		table[0] = INT_MAX;
		table[1] = 0;
		table[2] = 1;
		table[3] = 2;
		table[2147483647] = 32;
		return work(n);
	}
};