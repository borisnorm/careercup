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

void constructBSTFromPreorderTraversal(vector<int> &v, int ll, int rr, TreeNode *&root)
{
	root = new TreeNode(v[ll]);

	int i = ll + 1;
	while (i <= rr && v[i] < v[ll]) {
		++i;
	}
	if (ll + 1 <= i - 1) {
		constructBSTFromPreorderTraversal(v, ll + 1, i - 1, root->left);
	}
	if (i <= rr) {
		constructBSTFromPreorderTraversal(v, i, rr, root->right);
	}
}

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
	
	while (cin >> n && n > 0) {
		v.resize(n);
		for (i = 0; i < n; ++i) {
			cin >> v[i];
		}
		root = nullptr;
		constructBSTFromPreorderTraversal(v, 0, n - 1, root);
		inorderTraversal(root);
		cout << endl;
		
		clearTree(root);
		v.clear();
	}
	
	return 0;
}