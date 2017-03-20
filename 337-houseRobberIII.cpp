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
	int rob(TreeNode *root) {
		if (root == NULL) {
			return 0;
		}
		int val1 = 0, val2 = 0, val3 = 0, val4 = 0;
		int val5 = work(root->left, val1, val2);
		int val6 = work(root->right, val3, val4);
		return max(root->val + val1 + val2 + val3 + val4, val5 + val6);
	}

	int work(TreeNode *root, int &a, int &b) {
		if (root == NULL) {
			a = 0;
			b = 0;
			return 0;
		}
		int val1 = 0, val2 = 0, val3 = 0, val4 = 0;
		a = work(root->left, val1, val2);
		b = work(root->right, val3, val4);
		return max(root->val + val1 + val2 + val3 + val4, a + b);
	}
};