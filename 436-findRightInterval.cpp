/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

class Solution {
public:
	struct myInterval {
		int start, end, idx;
		const bool operator<(myInterval i) {
			return start < i.start || ((start == i.start) && (end < i.end));
		}
	};

	vector<int> findRightInterval(vector<Interval> &intervals) {
		vector<myInterval> list(intervals.size());
		for (int i = 0; i < intervals.size(); ++i) {
			list[i].start = intervals[i].start;
			list[i].end = intervals[i].end;
			list[i].idx = i;
		}
		sort(list.begin(), list.end());

		vector<int> result(intervals.size());
		for (int i = 0; i < list.size(); ++i) {
			int l = i + 1, r = list.size() - 1;
			if (list[r].start < list[i].end) {
				result[list[i].idx] = -1;
				continue;
			}
			while (l < r) {
				int mid = (l + r) / 2;
				if (list[mid].start >= list[i].end) {
					r = mid;
				} else {
					l = mid + 1;
				}
			}
			result[list[i].idx] = list[l].idx;
		}
		return result;
	}

};