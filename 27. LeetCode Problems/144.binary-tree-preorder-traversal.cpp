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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preorderHelper(root,ans);
        return ans;
    }
    
    void preorderHelper(TreeNode* root,vector<int> &ans)
    {
        if(root)
        {
            ans.push_back((root->val));
            preorderHelper(root->left,ans);
            preorderHelper(root->right,ans);
        }
    }
    
};