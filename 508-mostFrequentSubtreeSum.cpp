/*
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	int maxVal;
	vector<int> result;
	unordered_map<int, int> table;
	unordered_map<int, int>::iterator iter;
	vector<int> findFrequentTreeSum(TreeNode *root) {
		maxVal = 0;
		result.clear();
		table.clear();
		if (root == NULL) {
			return result;
		}
		int val = root->val + work(root->left) + work(root->right);
		++table[val];
		maxVal = max(maxVal, table[val]);
		for (iter = table.begin(); iter != table.end(); ++iter) {
			if (iter->second == maxVal) {
				result.push_back(iter->first);
			}
		}
		return result;
	}

	int work(TreeNode *root) {
		if (root == NULL) {
			return 0;
		}
		int val = root->val + work(root->left) + work(root->right);
		++table[val];
		maxVal = max(maxVal, table[val]);
		return val;
	}
};