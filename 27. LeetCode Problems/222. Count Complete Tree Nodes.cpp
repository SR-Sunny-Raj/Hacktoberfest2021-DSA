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
private:
    int complete(int h) { return (1 << h) - 1; }
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        TreeNode *p = root;
        int l = 0, r = 0;
        while (p) { p = p->left; ++l; }
        p = root;
        while (p) { p = p->right; ++r; }
        if (l == r) return complete(l);
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};
