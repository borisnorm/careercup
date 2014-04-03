// http://www.careercup.com/question?id=5344154741637120
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int _val = 0): val(_val), left(nullptr), right(nullptr) {};
};

void constructBinaryTree(TreeNode *&root)
{
	static string s;
	stringstream sio;
	int val;
	
	if (cin >> s && s == "#") {
		root = nullptr;
	} else {
		sio << s;
		if (sio >> val) {
			root = new TreeNode(val);
			constructBinaryTree(root->left);
			constructBinaryTree(root->right);
		} else {
			root = nullptr;
		}
	}
}

void preorderTraversal(TreeNode *root)
{
	if (root == nullptr) {
		cout << "# ";
	} else {
		cout << root->val << ' ';
		preorderTraversal(root->left);
		preorderTraversal(root->right);
	}
}

class Solution {
public:
	void sinkZero(TreeNode *root) {
		if (root == nullptr) {
			return;
		}
		
		if (root->val == 0) {
			TreeNode *ptr = findNonZeroNode(root);
			
			if (ptr != nullptr) {
				swap(root->val, ptr->val);
			} else {
				// all zero, no need to go down any more.
				return;
			}
		}
		sinkZero(root->left);
		sinkZero(root->right);
	};
private:
	TreeNode *findNonZeroNode(TreeNode *root) {
		if (root == nullptr) {
			return root;
		} else if (root->val != 0) {
			return root;
		} else {
			TreeNode *ptr = findNonZeroNode(root->left);
			if (ptr != nullptr) {
				return ptr;
			} else {
				return findNonZeroNode(root->right);
			}
		}
	};
};

int main()
{
	TreeNode *root;
	Solution sol;
	
	while (true) {
		constructBinaryTree(root);
 		if (root == nullptr) {
			break;
		}
		sol.sinkZero(root);
		preorderTraversal(root);
		cout << endl;
	}
	
	return 0;
}
