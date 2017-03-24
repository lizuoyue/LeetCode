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
	int pathSum(TreeNode *root, int sum) {
		if (root == NULL) return 0;
		return work(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
	}

	int work(TreeNode *root, int sum) {
		if (root == NULL) return 0;
		return (root->val == sum) + work(root->left, sum - root->val) + work(root->right, sum - root->val);
	}
};