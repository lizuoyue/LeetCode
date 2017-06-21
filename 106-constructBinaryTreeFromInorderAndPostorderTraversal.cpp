// preorder:  root left right
// inorder:   left root right
// postorder: left right root

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

	TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
		int len = inorder.size();
		if (len == 0) {
			return NULL;
		}
		return work(inorder, 0, postorder, 0, len);
	}

	TreeNode *work(vector<int> &inorder, int inBeg, vector<int> &postorder, int postBeg, int len){
		if (len <= 0) {
			return NULL;
		}

		int val = postorder[postBeg + len - 1], leftLen, rightLen;
		TreeNode *root = new TreeNode(val);

		for (int i = 0; i < len; ++i) {
			if (inorder[i + inBeg] == val) {
				leftLen = i;
				break;
			}
		}
		rightLen = len - 1 - leftLen;

		root->left = work(inorder, inBeg, postorder, postBeg, leftLen);
		root->right = work(inorder, inBeg + leftLen + 1, postorder, postBeg + leftLen, rightLen);
		return root;
	}

};
