/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x): val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	bool isSymmetric(TreeNode *root) {
		if (root == NULL) {
			return true;
		} else {
			return work(root->left, root->right);
		}
	}

	bool work(TreeNode *rootA, TreeNode *rootB) {
		if (rootA == NULL || rootB == NULL) {
			return (rootA == NULL && rootB == NULL);
		}
		if (rootA->val == rootB->val) {
			bool flagA = work(rootA->left, rootB->right);
			bool flagB = work(rootA->right, rootB->left);
			if (flagA && flagB) {
				return true;
			}
		}
		return false;
	}
};