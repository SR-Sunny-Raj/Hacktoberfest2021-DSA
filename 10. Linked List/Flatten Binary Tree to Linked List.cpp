// Link - https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
// Author - Shumbul Arifa

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
	TreeNode* prev = NULL;
public:
	void flatten(TreeNode* root) {
		if (!root)
			return;
		if (root->right)
			flatten(root->right);
		if (root->left)
			flatten(root->left);
		root->right = prev;
		root->left = NULL;
		prev = root;
	}
};
