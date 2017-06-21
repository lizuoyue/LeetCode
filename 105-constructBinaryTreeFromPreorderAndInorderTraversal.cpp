// preorder: root left right
// inorder:  left root right

/*
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

	TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
		int len = preorder.size();
		if (len == 0) {
			return NULL;
		}
		return work(preorder, 0, inorder, 0, len);
	}

	TreeNode *work(vector<int> &preorder, int preBeg, vector<int> &inorder, int inBeg, int len){
		if (len <= 0) {
			return NULL;
		}

		int val = preorder[preBeg], leftLen, rightLen;
		TreeNode *root = new TreeNode(val);

		for (int i = 0; i < len; ++i) {
			if (inorder[i + inBeg] == val) {
				leftLen = i;
				break;
			}
		}
		rightLen = len - 1 - leftLen;

		root->left = work(preorder, preBeg + 1, inorder, inBeg, leftLen);
		root->right = work(preorder, preBeg + 1 + leftLen, inorder, inBeg + 1 + leftLen, rightLen);
		return root;
	}

};
