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
	int countNodes(TreeNode* node) {
		if (node == NULL) {
			return 0;
		}
		return (1 + countNodes(node->left) + countNodes(node->right));
	}
	int kthSmallest(TreeNode* root, int k) {
		int count = countNodes(root->left);
		if (count < k - 1) {
			return kthSmallest(root->right, k - count - 1);
		} else if (count > k - 1) {
			return kthSmallest(root->left, k);
		} else {
			return root->val;
		}
	}
};
