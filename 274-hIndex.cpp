class Solution {
public:
	int hIndex(vector<int> &citation) {
		map<int, int> citationNum;
		map<int, int>::iterator iter;
		for (int i = 0; i < citation.size(); ++i) {
			++citationNum[citation[i]];
		}
		int sum = citation.size(), idx = 0;
		for (iter = citationNum.begin(); iter != citationNum.end(); ++iter) {
			idx = max(idx, min(sum, iter->first));
			sum -= iter->second;
		}
		return idx;
	}
};