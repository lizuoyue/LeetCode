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
	bool work(TreeNode* root, TreeNode* node, vector<TreeNode*> &path) {
		if (root == NULL) return false;
		if (root == node) {
			path.push_back(root);
			return true;
		}
		path.push_back(root);
		if (work(root->left, node, path)) return true;
		if (work(root->right, node, path)) return true;
		path.pop_back();
		return false;
	}
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == NULL) return NULL;
		if (p == q) return p;
		vector<TreeNode*> pPath, qPath;
		if (work(root, p, pPath) && work(root, q, qPath)) {
			pPath.push_back(NULL);
			qPath.push_back(NULL);
			int idx = 0;
			while (pPath[idx] == qPath[idx]) {
				++idx;
			}
			return qPath[idx - 1];
		} else {
			return NULL;
		}
	}
};