/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x): val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	ListNode *removeNthFromEnd(ListNode *head, int n) {
		vector<ListNode*> table;
		ListNode *p = head;
		while (p != NULL) {
			table.push_back(p);
			p = p->next;
		}
		if (table.size() >= n + 1) {
			table[table.size() - n - 1]->next = table[table.size() - n - 1]->next->next;
			return head;
		}
		return head->next;
	}
};