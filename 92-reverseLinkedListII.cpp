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
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		if (m == n) {
			return head;
		}
		ListNode *header = new ListNode(0);
		header->next = head;

		ListNode *pFirst = header;
		for (int i = 0; i < (m - 1); ++i) {
			pFirst = pFirst->next;
		}
		// pFirst->next == first element to be reversed
		ListNode *first = pFirst->next;
		ListNode *second = first->next;
		ListNode *temp;
		for (int i = 0; i < (n - m); ++i) {
			temp = second->next;
			second->next = first;
			first = second;
			second = temp;
		}
		pFirst->next->next = temp;
		pFirst->next = first;
		if (m == 1) {
			return first;
		} else {
			return head;
		}
	}
};
