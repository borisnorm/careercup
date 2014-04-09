// http://www.careercup.com/question?id=5917873302142976
#include <iostream>
#include <unordered_map>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode*random;
	ListNode(int _val = 0): val(_val), next(nullptr), random(nullptr) {};
};

class Solution {
public:
	ListNode *copyListWithRandomPointer(ListNode *head) {
		if (head == nullptr) {
			return nullptr;
		}
		ListNode *new_head;
		ListNode *p1, *p2;
		
		p1 = head;
		while (p1 != nullptr) {
			p2 = new ListNode(p1->val);
			p2->next = p1->next;
			p1->next = p2;
			p1 = p1->next->next;
		}
		
		p1 = head;
		while (p1 != nullptr) {
			p1->next->random = p1->random == nullptr ? nullptr : p1->random->next;
			p1 = p1->next->next;
		}
		new_head = splitList(head);
		
		return new_head;
	};
private:
	ListNode *splitList(ListNode *head) {
		ListNode *head1, *head2;
		ListNode *ptr1, *ptr2;
		
		// head1 is the original list.
		head1 = ptr1 = nullptr;
		// head2 is the new list.
		head2 = ptr2 = nullptr;
		while (true) {
			if (head == nullptr) {
				break;
			}
			if (head1 == nullptr) {
				head1 = ptr1 = head;
			} else {
				ptr1->next = head;
				ptr1 = ptr1->next;
			}
			head = head->next;
			
			if (head == nullptr) {
				break;
			}
			if (head2 == nullptr) {
				head2 = ptr2 = head;
			} else {
				ptr2->next = head;
				ptr2 = ptr2->next;
			}
			head = head->next;
		}
		
		return head2;
	};
};

void deleteList(ListNode *&head)
{
	ListNode *ptr;
	
	ptr = head;
	while (head != ptr) {
		ptr = head;
		head = head->next;
		delete ptr;
	}
}

int main()
{
	int val;
	int n;
	int i;
	ListNode *head1, *head2;
	ListNode *ptr;
	unordered_map<int, ListNode *> um;
	Solution sol;
	
	while (cin >> n && n > 0) {
		head1 = head2 = nullptr;
		for (i = 0; i < n; ++i) {
			cin >> val;
			if (head1 == nullptr) {
				head1 = ptr = new ListNode(val);
			} else {
				ptr->next = new ListNode(val);
				ptr = ptr->next;
			}
			um[i] = ptr;
		}
		
		ptr = head1;
		for (i = 0; i < n; ++i) {
			cin >> val;
			if (val >= 0) {
				ptr->random = um[val];
			} else {
				ptr->random = nullptr;
			}
			ptr = ptr->next;
		}
		
		head2 = sol.copyListWithRandomPointer(head1);
		ptr = head2;
		while (ptr != nullptr) {
			cout << ptr->val << ' ';
			cout << (ptr->random != nullptr ? ptr->random->val : -1) << endl;
			ptr = ptr->next;
		}
		
		deleteList(head1);
		deleteList(head2);
	}
	
	return 0;
}