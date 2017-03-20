/*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x): val(x), next(NULL) {}
 * };
 */
/*
class Solution {
public:
	ListNode *insertionSortList(ListNode *head) {
		if (head == NULL) {
			return NULL;
		}
		ListNode *sortHead = new ListNode(head->val);
		ListNode *p = head->next;
		while (p != NULL) {
			ListNode *sp = sortHead, *spOld = NULL;
			while (sp != NULL && p->val >= sp->val) {
				spOld = sp;
				sp = sp->next;
			}
			ListNode *newNode = new ListNode(p->val);
			if (sp == NULL) {
				spOld->next = newNode;
			} else {
				newNode->next = sp;
				if (spOld == NULL) {
					sortHead = newNode;
				} else {
					spOld->next = newNode;
				}
			}
			p = p->next;
		}
		return sortHead;
	}
};
*/
class Solution {
public:
	ListNode *insertionSortList(ListNode *head) {
		if (head == NULL) {
			return NULL;
		}

		vector<int> list;
		ListNode *p = head;
		while (p != NULL) {
			list.push_back(p->val);
			p = p->next;
		}

		sort(list.begin(), list.end());

		p = head;
		for (int i = 0; i < list.size(); ++i) {
			p->val = list[i];
			p = p->next;
		}

		return head;
	}
};