/*
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
	vector<TreeNode*> generateTrees(int n) {
		if (n > 0) {
			return work(1, n);
		} else {
			vector<TreeNode*> result;
			return result;
		}
	}
	vector<TreeNode*> work(int x, int y) {
		vector<TreeNode*> result;
		if (x > y) {
			result.push_back(NULL);
			return result;
		}
		for (int i = x; i <= y; ++i) {
			vector<TreeNode*> leftList = work(x, i - 1);
			vector<TreeNode*> rightList = work(i + 1, y);
			for (int j = 0; j < leftList.size(); ++j) {
				for (int k = 0; k < rightList.size(); ++k) {
					TreeNode *newNode = new TreeNode(i);
					newNode->left = leftList[j];
					newNode->right = rightList[k];
					result.push_back(newNode);
				}
			}
		}
		return result;
	}
};