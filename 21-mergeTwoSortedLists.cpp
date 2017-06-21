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
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == NULL) return l2;
		if (l2 == NULL) return l1;
		ListNode *head, *p1, *p2;
		if (l1->val < l2->val) {
			head = l1;
			p1 = head->next;
			p2 = l2;
		} else {
			head = l2;
			p1 = l1;
			p2 = l2->next;
		}
		ListNode* old = head;
		while (p1 != NULL && p2 != NULL) {
			if (p1->val < p2->val) {
				old->next = p1;
				p1 = p1->next;
			} else {
				old->next = p2;
				p2 = p2->next;
			}
			old = old->next;
		}
		if (p1 == NULL) old->next = p2;
		if (p2 == NULL) old->next = p1;
		return head;
	}
};