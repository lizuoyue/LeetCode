class Solution {
public:
	int compareVersion(string version1, string version2) {
		vector<int> dot1(1, -1), dot2(1, -1);
		for(int i = 0; i < version1.length(); ++i) {
			if (version1[i] == '.') {
				dot1.push_back(i);
			}
		}
		dot1.push_back(version1.length());
		for(int i = 0; i < version2.length(); ++i) {
			if (version2[i] == '.') {
				dot2.push_back(i);
			}
		}
		dot2.push_back(version2.length());
		vector<int> num1, num2;
		for (int i = 0; i < (int(dot1.size()) - 1); ++i) {
			num1.push_back(stoi(version1.substr(dot1[i] + 1, dot1[i + 1])));
		}
		for (int i = 0; i < (int(dot2.size()) - 1); ++i) {
			num2.push_back(stoi(version2.substr(dot2[i] + 1, dot2[i + 1])));
		}
		if (num1.size() < num2.size()) {
			for (int i = num1.size(); i < num2.size(); ++i) {
				num1.push_back(0);
			}
		}
		if (num2.size() < num1.size()) {
			for (int i = num2.size(); i < num1.size(); ++i) {
				num2.push_back(0);
			}
		}
		for (int i = 0; i < min(num1.size(), num2.size()); ++i) {
			if (num1[i] < num2[i]) {
				return -1;
			} else if (num1[i] > num2[i]) {
				return 1;
			}
		}
		return 0;
	}
};