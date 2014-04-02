// http://www.careercup.com/question?id=5412018236424192
#include <unordered_map>
using namespace std;

struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {};
};

class Solution {
public:
	RandomListNode *copyRandomList(RandomListNode *head) {
		// IMPORTANT: Please reset any member data you declared, as
		// the same Solution instance will be reused for each test case.
		int n;
		
		if(nullptr == head){
			return nullptr;
		}
		
		n = 0;
		RandomListNode *ptr;
		
		ptr = head;
		while(ptr != nullptr){
			++n;
			mri[ptr] = n;
			ptr = ptr->next;
		}
		
		RandomListNode *root, *tail;
		ptr = head;
		
		int i = 0;
		tail = root = nullptr;
		while(ptr != nullptr){
			++i;
			if (root == nullptr) {
				root = tail = new RandomListNode(ptr->label);
			} else {
				tail->next = new RandomListNode(ptr->label);
				tail = tail->next;
			}
			mir[i] = tail;
			ptr = ptr->next;
		}
		
		RandomListNode *p1, *p2;
		
		p1 = head;
		p2 = root;
		while(p1 != nullptr){
			if(p1->random != nullptr){
				p2->random = mir[mri[p1->random]];
			}
			p1 = p1->next;
			p2 = p2->next;
		}
		
		mir.clear();
		mri.clear();
		
		return root;
	}
private:
	unordered_map<RandomListNode *, int> mri;
	unordered_map<int, RandomListNode *> mir;
};