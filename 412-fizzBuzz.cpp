class Solution {
public:
	vector<string> fizzBuzz(int n) {
		vector<string> result;
		for (int i = 1; i <= n; ++i) {
			int flag = 2 * (i % 3 == 0) + (i % 5 == 0);
			switch (flag) {
				case 3: result.push_back("FizzBuzz"); break;
				case 2: result.push_back("Fizz"); break;
				case 1: result.push_back("Buzz"); break;
				case 0: result.push_back(to_string(i)); break;
			}
		}
		return result;
	}
};