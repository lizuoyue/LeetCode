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
	ListNode* rotateRight(ListNode *head, int k) {

		ListNode *p = head, *last, *pre;

		int num = 0;
		while (p) {
			++num;
			last = p;
			p = p->next;
		}

		if (num == 0) {
			return NULL;
		} else {
			k = k % num;
		}

		if (k == 0) {
			return head;
		}

		p = head;
		for (int i = 0; i < (num - k); ++i) {
			pre = p;
			p = p->next;
		}

		pre->next = NULL;
		last->next = head;

		return p;

	}
};