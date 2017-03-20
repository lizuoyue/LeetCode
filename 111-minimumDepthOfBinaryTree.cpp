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
	int minDepth(TreeNode *root) {
		if (root == NULL) {
			return 0;
		}
		if (root->left == NULL && root->right == NULL) {
			return 1;
		}
		int val = INT_MAX;
		if (root->left != NULL) {
			val = min(val, minDepth(root->left));
		}
		if (root->right != NULL) {
			val = min(val, minDepth(root->right));
		}
		return 1 + val;
	}
};