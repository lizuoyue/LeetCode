class Solution {
public:
	int maxDistance(vector< vector<int> > &array) {
		int m1 = INT_MAX, idx1;
		int m2 = (1 << 31), idx2;
		for (int i = 0; i < array.size(); ++i) {
			if (array.size() > 0) {
				if (array[i][0] < m1) {
					m1 = array[i][0];
					idx1 = i;
				}
				if (array[i].back() > m2) {
					m2 = array[i].back();
					idx2 = i;
				}
			}
		}
		if (idx1 != idx2) {
			return m2 - m1;
		}
		int sm1 = INT_MAX;
		int sm2 = (1 << 31);
		for (int i = 0; i < array.size(); ++i) {
			if (array.size() > 0) {
				if (i != idx1 && array[i][0] <= sm1) {
					sm1 = array[i][0];
				}
				if (i != idx2 && array[i].back() >= sm2) {
					sm2 = array[i].back();
				}
			}
		}
		return max(sm2 - m1, m2 - sm1);
	}
};