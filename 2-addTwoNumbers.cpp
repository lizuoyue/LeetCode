/**
 * Definition for singly-linked list.
 *	struct ListNode {
 *		int val;
 *		ListNode *next;
 *		ListNode(int x) : val(x), next(NULL) {}
 *	};
 */

int dig_sum(int val1, int val2, int &carry) {
	int tmp_sum = val1 + val2 + carry;
	if (tmp_sum > 9) {
		tmp_sum -= 10;
		carry = 1;
	} else {
		carry = 0;
	}
	return tmp_sum;
}

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* head = new ListNode(-1);
		ListNode* tmp = head;
		int carry = 0;
		while (l1 != NULL && l2 != NULL) {
			tmp->next = new ListNode(0);
			tmp = tmp->next;
			tmp->val = dig_sum(l1->val, l2->val, carry);
			l1 = l1->next;
			l2 = l2->next;
		}
		ListNode* l = NULL;
		if (l1 != NULL) {
			l = l1;
		}
		if (l2 != NULL) {
			l = l2;
		}
		while (l != NULL) {
			tmp->next = new ListNode(0);
			tmp = tmp->next;
			tmp->val = dig_sum(l->val, 0, carry);
			l = l-> next;
		}
		if (carry == 1) {
			tmp->next = new ListNode(1);
		} else {
			tmp->next = NULL;
		}
		return head->next;
	}
};