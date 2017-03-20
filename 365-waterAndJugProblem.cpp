class Solution {
public:
	bool canMeasureWater(int x, int y, int z) {
		if (z >= 0 && z <= (x + y)) {
			int a = gcd(x, y);
			if (a == 0) {
				return (z == 0);
			}
			return ((z % a) == 0);
		}
		return false;
	}
	int gcd(int x, int y) {
		int a = min(x, y);
		int b = max(x, y);
		if (a == 0) {
			return b;
		}
		return gcd(a, b - a * (b / a));
	}
};