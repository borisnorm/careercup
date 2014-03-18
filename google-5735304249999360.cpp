// http://www.careercup.com/question?id=5735304249999360
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int _val = 0): val(_val), next(nullptr) {};
};

class Solution {
	void insertElement(ListNode *&head, int new_val) {
		if (head == nullptr) {
			head = new ListNode(new_val);
			head->next = head;
			return;
		}
		
		ListNode *ptr = nullptr;
		if (new_val <= head->val) {
			ptr = new ListNode(head->val);
			ptr->next = head->next;
			head->next = ptr;
			head->val = new_val;
		} else {
			ListNode *prev = head;
			ListNode *ptr2 = head->next;
			while (ptr2 != head && ptr2->val < new_val) {
				prev = prev->next;
				ptr2 = ptr2->next;
			}
			ptr = new ListNode(new_val);
			ptr->next = ptr2;
			prev->next = ptr;
		}
	};
};