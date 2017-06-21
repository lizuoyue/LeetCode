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
	int countNodes(TreeNode* root) {
		if (root == NULL) return 0;
		int nl = 0, nr = 0;
		TreeNode* p;
		p = root;
		while (p != NULL) {
			p = p->left;
			++nl;
		}
		p = root;
		while (p != NULL) {
			p = p->right;
			++nr;
		}
		if (nl == nr) {
			return pow(2, nl) - 1;
		} else {
			return 1 + countNodes(root->left) + countNodes(root->right);
		}
	}
};