struct TN {
	TN* next[2];
	TN() {
		next[0] = NULL;
		next[1] = NULL;
	}
};

class Solution {
public:
	TN* buildTrie(vector<int> &num) {
		TN* root = new TN(), *temp;
		for (int i = 0; i < num.size(); ++i) {
			temp = root;
			for (int j = 31; j >= 0; --j) {
				int idx = (num[i] & (1 << j)) > 0;
				if (temp->next[idx] == NULL) {
					temp->next[idx] = new TN();
				}
				temp = temp->next[idx];
			}
		}
		return root;
	}
	int findMax(TN* root, int num) {
		TN* temp = root;
		vector<int> record;
		for (int i = 31; i >= 0; --i) {
			int idx = (num & (1 << i)) > 0;
			if (temp->next[!idx] == NULL) {
				record.push_back(idx);
				temp = temp->next[idx];
			} else {
				record.push_back(!idx);
				temp = temp->next[!idx];
			}
		}
		int result = 0;
		for (int i = 0; i < record.size(); ++i) {
			result |= (record[i] << (31 - i));
		}
		return result;
	}
	int findMaximumXOR(vector<int> &num) {
		TN* root = buildTrie(num);
		int result = 0;
		for (int i = 0; i < num.size(); ++i) {
			result = max(result, (findMax(root, num[i]) ^ num[i]));
		}
		return result;
	}
};