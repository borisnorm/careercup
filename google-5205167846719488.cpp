// http://www.careercup.com/question?id=5205167846719488
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int _val = 0): val(_val), left(nullptr), right(nullptr) {};
};

class Solution {
public:
	int nextLargestNumber(TreeNode *root, int val) {
		if (root == nullptr) {
			// nothing to do
			return val;
		}
		
		left_top = nullptr;
		return findRecursive(root, val);
	}
private:
	TreeNode *left_top;
	
	int findRecursive(TreeNode *root, int val) {
		if (root == nullptr) {
			// not found, return val
			return val;
		} else if (root->val > val) {
			left_top = root;
			return findRecursive(root->left, val);
		} else if (root->val < val) {
			return findRecursive(root->right, val);
		} else {
			if (left_top == nullptr) {
				// val is the greatest of all.
				return val;
			}
			if (root->right == nullptr) {
				return left_top->val;
			}
			
			left_top = root->right;
			while (left_top->left != nullptr) {
				left_top = left_top->left;
			}
			return left_top->val;
		}
	};
}