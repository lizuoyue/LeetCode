class Solution {
public:
	int hIndex(vector<int> &citation) {
		if (citation.size() == 0) {
			return 0;
		}
		int l = 0, r = citation.size() - 1;
		while (l < r) {
			int mid = (l + r) / 2;
			if ((citation.size() - mid) <= citation[mid]) {
				r = mid;
			} else {
				l = mid + 1;
			}
		}
		return min(int(citation.size()) - l, citation[l]);
	}
};