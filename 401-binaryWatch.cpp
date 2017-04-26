class Solution {
public:
	vector<string> readBinaryWatch(int num) {
		vector<string> result;
		if (num > 10 || num < 0) {
			return result;
		}
		vector< vector<int> > hour(4);
		vector< vector<int> > minute(6);
		for (int i = 0; i < 60; ++i) {
			int count = 0;
			for (int s = 0; s < 6; ++s) {
				if (i & (1 << s)) {
					++count;
				}
			}
			if (i < 12) {
				hour[count].push_back(i);
			}
			minute[count].push_back(i);
		}
		/*
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < hour[i].size(); ++j) {
				cout << hour[i][j] << " ";
			}
			cout << endl;
		}
		for (int i = 0; i < 6; ++i) {
			for (int j = 0; j < minute[i].size(); ++j) {
				cout << minute[i][j] << " ";
			}
			cout << endl;
		}
		*/
		for (int i = 0; i <= min(3, num); ++i) {
			int j = num - i;
			if (j >= 0 && j <= 5) {
				for (int k = 0; k < hour[i].size(); ++k) {
					for (int l = 0; l < minute[j].size(); ++l) {
						if (minute[j][l] < 10) {
							result.push_back(to_string(hour[i][k]) + ":0" + to_string(minute[j][l]));
						} else {
							result.push_back(to_string(hour[i][k]) + ":" + to_string(minute[j][l]));
						}
					}
				}
			}
		}
		return result;
	}
};