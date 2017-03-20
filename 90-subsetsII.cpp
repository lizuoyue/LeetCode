class Solution {
public:

	map<int, int> table;
	map<int, int>::iterator iter;
	vector< vector<int> > result;
	vector<int> temp, list;

	vector< vector<int> > subsetsWithDup(vector<int> &num) {

		table.clear();
		for (int i = 0; i < num.size(); ++i) {
			++table[num[i]];
		}

		list.clear();
		for (iter = table.begin(); iter != table.end(); ++iter) {
			list.push_back(iter->first);
		}
		result.clear();

		temp.clear();
		backtracking(list, 0);
		return result;

	}


	void backtracking(vector<int> &list, int id) {

		for (int i = 0; i < table[list[id]]; ++i) {
			temp.push_back(list[id]);
			if (id != (list.size() - 1)) {
				backtracking(list, id + 1);
			} else {
				result.push_back(temp);
			}
		}
		for (int i = 0; i < table[list[id]]; ++i) {
			temp.pop_back();
		}
		if (id != (list.size() - 1)) {
			backtracking(list, id + 1);
		} else {
			result.push_back(temp);
		}
		return;

	}

};