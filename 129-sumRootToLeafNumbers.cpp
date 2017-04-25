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

	int result;

	void work(TreeNode *root, vector<int> &path) {
		if (root->left == NULL && root->right == NULL) {
			path.push_back(root->val);
			int sum = 0;
			for (int i = 0; i < path.size(); ++i) {
				sum = sum * 10 + path[i];
			}
			result += sum;
			path.pop_back();
		} else {
			path.push_back(root->val);
			if (root->left != NULL) {
				work(root->left, path);
			}
			if (root->right != NULL) {
				work(root->right, path);
			}
			path.pop_back();
		}
	}

	int sumNumbers(TreeNode *root) {
		result = 0;
		if (root == NULL) return 0;
		vector<int> path;
		work(root, path);
		return result;
	}
};