/**
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
	vector<int> result;
	void helper(TreeNode *root) {
		if (root == NULL) {
			return;
		}
		helper(root->left);
		result.push_back(root->val);
		helper(root->right);
		return;
	}
	vector<int> inorderTraversal(TreeNode *root) {
		result.clear();
		helper(root);
		return result;
	}
};