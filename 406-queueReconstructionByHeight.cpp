class Solution {
public:
	static bool comp(pair<int, int> &a, pair<int, int> &b) {
		return (a.first > b.first) || (a.first == b.first && a.second < b.second);
	}
	vector< pair<int, int> > reconstructQueue(vector< pair<int, int> > &people) {
		sort(people.begin(), people.end(), comp);
		vector< pair<int, int> > result;
		for (int i = 0; i < people.size(); ++i) {
			result.insert(result.begin() + people[i].second, people[i]);
		}
		return result;
	}
};