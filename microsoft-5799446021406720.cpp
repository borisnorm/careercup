// http://www.careercup.com/question?id=5799446021406720
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

struct TrieNode {
	char ch;
	vector<TrieNode *> child;
	TrieNode(char _ch = 0): ch(_ch), child(vector<TrieNode *>()) {};
};

TrieNode *deserializeFromString(const string &str)
{
	TrieNode *root;
	TrieNode *ptr;
	stack<TrieNode *>  st;
	
	int i, n;
	
	root = nullptr;
	n = (int)str.length();
	i = 0;
	while (i < n) {
		if (str[i] == '>') {
			st.pop();
			++i;
		} else {
			ptr = new TrieNode(str[i]);
			i += 2;
			if (st.empty()) {
				root = ptr;
			} else {
				(st.top()->child).push_back(ptr);
			}
			st.push(ptr);
		}
	}
	
	return root;
}

void preorderTraversal(TrieNode *root)
{
	if (root == nullptr) {
		return;
	}
	cout << root->ch << ' ';
	for (int i = 0; i < (int)root->child.size(); ++i) {
		preorderTraversal(root->child[i]);
	}
}

int main()
{
	TrieNode *root = nullptr;
	string str;
	
	while (cin >> str) {
		root = deserializeFromString(str);
		preorderTraversal(root);
		cout << endl;
	}
	
	return 0;
}