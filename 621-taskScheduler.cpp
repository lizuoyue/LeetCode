class Solution {
public:
	int leastInterval(vector<char> &task, int n) {
		if (task.size() == 0) return 0;
		unordered_map<char, int> table;
		for (char c: task) {
			++table[c];
		}
		priority_queue<int> pq;
		for (pair<char, int> p: table) {
			pq.push(p.second);
		}
		int time = 0, period = n + 1;
		while (!pq.empty()) {
			int single = 0;
			vector<int> temp;
			for (int i = 0; i < period; ++i) {
				if (!pq.empty()) {
					temp.push_back(pq.top());
					pq.pop();
					++single;
				}
			}
			for (int num: temp) {
				if (num > 1) {
					pq.push(num - 1);
				}
			}
			if (!pq.empty()) {
				time += period;
			} else {
				time += single;
			}
		}
		return time;
	}
};
