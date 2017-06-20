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
	vector< vector<int> > levelOrder(TreeNode *root) {
		vector< vector<int> > result;
		if (root == NULL) return result;
		queue< pair<TreeNode*, int> > q;
		q.push(make_pair(root, 0));
		while (q.size() > 0) {
			int layer = q.front().second;
			if (result.size() <= layer) {
				result.resize(layer + 1);
			}
			result[layer].push_back(q.front().first->val);
			if (q.front().first->left != NULL) {
				q.push(make_pair(q.front().first->left, layer + 1));
			}
			if (q.front().first->right != NULL) {
				q.push(make_pair(q.front().first->right, layer + 1));
			}
			q.pop();
		}
		return result;
	}
};
