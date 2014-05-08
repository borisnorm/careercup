// http://www.careercup.com/question?id=5162732873580544
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int _val = 0): val(_val), left(nullptr), right(nullptr) {};
};

void inorderTraversal(TreeNode *root)
{
	if (nullptr == root) {
		return;
	}
	inorderTraversal(root->left);
	cout << root->val << ' ';
	inorderTraversal(root->right);
}

void clearTree(TreeNode *&root)
{
	if (nullptr == root) {
		return;
	}
	clearTree(root->left);
	clearTree(root->right);
	delete root;
	root = nullptr;
}

int main()
{
	vector<int> v;
	int n;
	int i;
	TreeNode *root;
	TreeNode *tmp;
	vector<TreeNode *> st;
	
	while (cin >> n && n > 0) {
		v.resize(n);
		for (i = 0; i < n; ++i) {
			cin >> v[i];
		}
		
		root = new TreeNode(v[0]);
		st.push_back(root);
		for (i = 1; i < n; ++i) {
			if (v[i] < st[st.size() - 1]->val) {
				tmp = new TreeNode(v[i]);
				st[st.size() - 1]->left = tmp;
				st.push_back(tmp);
			} else if (st.size() == 1 || v[i] < st[st.size() - 2]->val) {
				tmp = new TreeNode(v[i]);
				st[st.size() - 1]->right = tmp;
				st.push_back(tmp);
			} else {
				st.pop_back();
				--i;
			}
		}
		
		inorderTraversal(root);
		cout << endl;
		
		v.clear();
		st.clear();
		clearTree(root);
	}
	
	return 0;
}