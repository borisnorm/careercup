// http://www.careercup.com/question?id=5672369481842688
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

int height(TreeNode *root)
{
	return root ? 1 + max(height(root->left), height(root->right)) : 0;
}

void constructBinaryTree(TreeNode *&root)
{
	static int val;
	static string str;
	static stringstream sio;
	
	if (cin >> str && str != "#") {
		sio << str;
		sio >> val;
		root = new TreeNode(val);
		constructBinaryTree(root->left);
		constructBinaryTree(root->right);
	} else {
		root = nullptr;
	}
}

void deleteTree(TreeNode *&root)
{
	if (root == nullptr) {
		return;
	} else {
		deleteTree(root->left);
		deleteTree(root->right);
		delete root;
		root = nullptr;
	}
}

int main()
{
	TreeNode *root;
	
	while (true) {
		constructBinaryTree(root);
		if (root == nullptr) {
			break;
		}
		cout << height(root) << endl;
		deleteTree(root);
	}
	
	return 0;
}