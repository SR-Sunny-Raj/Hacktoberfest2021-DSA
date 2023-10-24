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
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorderHelper(root,ans);
        return ans;
    }
    
    void inorderHelper(TreeNode* root,vector<int>&ans)
    {
        if(root)
        {
            inorderHelper(root->left,ans);
            ans.push_back(root->val);
            inorderHelper(root->right,ans);
        }
    }
};