/*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x): val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	ListNode* detectCycle(ListNode *head) {
		if (head == NULL || head->next == NULL) {
			return NULL;
		}
		ListNode *step1 = head, *step2 = head;
		while (step2->next != NULL && step2->next->next != NULL) {
			step1 = step1->next;
			step2 = step2->next->next;
			if (step1 == step2) {
				ListNode *entry = head;
				while (entry != step1) {
					step1 = step1->next;
					entry = entry->next;
				}
				return entry;
			}
		}
		return NULL;
	}
};