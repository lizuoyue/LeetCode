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

	vector< vector<int> > result;

	void work(TreeNode *root, vector<int> &path, int diff) {
		if (root->left == NULL && root->right == NULL) {
			if (diff == root->val) {
				path.push_back(root->val);
				result.push_back(path);
				path.pop_back();
			}
		} else {
			path.push_back(root->val);
			if (root->left != NULL) {
				work(root->left, path, diff - root->val);
			}
			if (root->right != NULL) {
				work(root->right, path, diff - root->val);
			}
			path.pop_back();
		}
	}

	vector< vector<int> > pathSum(TreeNode *root, int sum) {
		result.clear();
		if (root == NULL) return result;
		vector<int> path;
		work(root, path, sum);
		return result;
	}
};