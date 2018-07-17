/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void dfs(TreeNode* root, int v, int d, int x) {
	if (x == d) {
		TreeNode* new_l = new TreeNode(v);
		TreeNode* new_r = new TreeNode(v);
		new_l->left = root->left;
		new_r->right = root->right;
		root->left = new_l;
		root->right = new_r;
	} else {
		if (root->left != NULL) {
			dfs(root->left, v, d, x + 1);
		}
		if (root->right != NULL) {
			dfs(root->right, v, d, x + 1);
		}
	}
	return;
}


class Solution {
public:
	TreeNode* addOneRow(TreeNode* root, int v, int d) {
		if (d < 1) {
			return root;
		}
		if (d == 1) {
			TreeNode* new_root = new TreeNode(v);
			new_root->left = root;
			return new_root;
		}
		dfs(root, v, d, 2);
		return root;
	}
};