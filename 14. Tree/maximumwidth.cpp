#include<bits/stdc++.h>
using namespace std;

class TreeNode{
  public:  
    TreeNode* left; 
    int val;
    TreeNode* right;

    TreeNode(int val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

// written the header file just for 0 errors. 

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
    int maxWidth = 0;
    
    void helper(TreeNode* root, vector<long> &ans, long level, long long unsigned idx)
    {
        if(!root){
            return;
        }
        
        if(level == ans.size()){
            ans.push_back(idx);
        }
        
        if(maxWidth < (idx - ans[level] + 1)){
            maxWidth = idx - ans[level] + 1;
        }
        
        helper(root->left, ans, level + 1, idx * 2);
        helper(root->right, ans, level + 1, idx * 2 + 1);
    }
    
    int widthOfBinaryTree(TreeNode* root)
    {
        vector<long> ans;
        
        helper(root,ans,0,0);
        
        return maxWidth;
    }
};