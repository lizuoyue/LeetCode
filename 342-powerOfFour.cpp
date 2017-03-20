/*
class Solution {
public:
	bool isPowerOfFour(int num) {
		for (int i = 0; i < 32; i += 2) {
			if (num == (1 << i)) {
				return true;
			}
		}
		return false;
	}
};
*/
class Solution {
public:
	bool isPowerOfFour(int num) {
		return !(num & (num - 1)) && (num & 0x55555555);
	}
};