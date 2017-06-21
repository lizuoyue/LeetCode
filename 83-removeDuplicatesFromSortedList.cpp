/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == NULL) return NULL;
		ListNode *old = head, *now = head->next;
		while (now != NULL) {
			if (now->val != old->val) {
				old = old->next;
				old->val = now->val;
			}
			now = now->next;
		}
		old->next = NULL;
		return head;
	}
};