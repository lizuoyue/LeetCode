/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
	vector<ListNode*> list_node;
	TreeNode* helper(int begin, int end) {
		if (begin >= end) {
			return NULL;
		}
		int center = (begin + end) / 2;
		TreeNode* root = new TreeNode(list_node[center]->val);
		root->left = helper(begin, center);
		root->right = helper(center + 1, end);
		return root;
	}
	TreeNode* firstWay(ListNode* head) {
		if (head == NULL) return NULL;
		list_node.clear();
		while (head != NULL) {
			list_node.push_back(head);
			head = head->next;
		}
		return helper(0, list_node.size());
	}
	TreeNode* sortedListToBST(ListNode* head) {
		return firstWay(head);
	}
};