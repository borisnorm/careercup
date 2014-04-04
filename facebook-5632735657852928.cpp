// http://www.careercup.com/question?id=5632735657852928
#include <climits>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int _val = 0): val(_val), left(nullptr),right(nullptr) {};
};

class Solution {
public:
	bool isBST(TreeNode *root) {
		if (root == nullptr) {
			return false;
		}
		
		max_val = INT_MIN;
		res = true;
		first_node = true;
		isBSTRecursive(root);
		
		return res;
	};
private:
	int max_val;
	bool res;
	bool first_node;
	
	void isBSTRecursive(TreeNode *root) {
		if (!res) {
			return;
		}
		
		// root is guaranteed to be not nullptr.
		if (root->left) {
			isBSTRecursive(root->left);
		}
		if (first_node || root->val > max_val) {
			first_node = false;
			max_val = root->val;
		} else {
			res = false;
			return;
		}
		if (root->right) {
			isBSTRecursive(root->right);
		}
	};
};

void construcTree(TreeNode *&root)
{
	int val;
	stringstream sio;
	string s;
	
	if (cin >> s && s != "#") {
		sio << s;
		sio >> val;
		root = new TreeNode(val);
		construcTree(root->left);
		construcTree(root->right);
	} else {
		root = nullptr;
	}
}

void deleteTree(TreeNode *&root)
{
	if (root == nullptr) {
		return;
	}
	deleteTree(root->left);
	deleteTree(root->right);
	delete root;
	root = nullptr;
}

int main()
{
	TreeNode *root;
	Solution sol;
	
	while (true) {
		construcTree(root);
		if (root == nullptr) {
			break;
		}
		
		cout << (sol.isBST(root) ? "Valid BST" : "Invalid BST") << endl;
		
		deleteTree(root);
	}
	
	return 0;
}