/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool compare(Interval a, Interval b) {
	return a.start < b.start;
}
class Solution {
public:
	vector<Interval> merge(vector<Interval> &intervals) {
		vector<Interval> result;
		if (intervals.size() == 0) return result;
		sort(intervals.begin(), intervals.end(), compare);
		Interval inter = intervals[0];
		for (int i = 1; i < intervals.size(); ++i) {
			if (intervals[i].start <= inter.end) {
				inter.end = max(inter.end, intervals[i].end);
			} else {
				result.push_back(inter);
				inter = intervals[i];
			}
		}
		result.push_back(inter);
		return result;
	}
};