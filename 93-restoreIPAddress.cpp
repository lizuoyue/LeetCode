class Solution {
public:
	bool valid(string s) {
		if (s.length() > 1 && s[0] == '0') {
			return false;
		}
		return true;
	}
	vector<string> restoreIpAddresses(string s) {
		vector<string> result;
		if (s.length() < 4 || s.length() > 12) {
			return result;
		}
		for (int i = 1; i <= 3; ++i) {
			for (int j = 1; j <= 3; ++j) {
				for (int k = 1; k <= 3; ++k) {
					int len = s.length() - i - j - k;
					if (len > 0 && len < 4) {
						string sa = s.substr(0, i);
						string sb = s.substr(i, j);
						string sc = s.substr(i + j, k);
						string sd = s.substr(i + j + k, s.length());
						if (valid(sa) && valid(sb) && valid(sc) && valid(sd)) {
							int a = stoi(sa);
							int b = stoi(sb);
							int c = stoi(sc);
							int d = stoi(sd);
							if (a < 256 && b < 256 && c < 256 && d < 256) {
								result.push_back(to_string(a) + "." + to_string(b) + "." + to_string(c) + "." + to_string(d));
							}
						}
					}
				}
			}
		}
		return result;
	}
};