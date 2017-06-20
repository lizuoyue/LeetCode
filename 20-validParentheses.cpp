#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	bool isValid(string s) {
		vector<char> stack;
		for (int i = 0; i < s.length(); ++i) {
			if (stack.size() == 0) {
				if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
					return false;
				} else {
					stack.push_back(s[i]);
				}
			} else {
				if (s[i] == ')') {
					if (stack.back() != '(') {
						return false;
					} else {
						stack.pop_back();
					}
				} else if (s[i] == ']') {
					if (stack.back() != '[') {
						return false;
					} else {
						stack.pop_back();
					}
				} else if (s[i] == '}') {
					if (stack.back() != '{') {
						return false;
					} else {
						stack.pop_back();
					}
				} else {
					stack.push_back(s[i]);
				}
			}
		}
		return (stack.size() == 0);
	}
};

int main(void) {
	string s; cin >> s;
	Solution solu;
	cout << solu.isValid(s) << endl;
}