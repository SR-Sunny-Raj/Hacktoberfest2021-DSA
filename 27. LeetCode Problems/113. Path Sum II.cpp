
/* 
Problem Link - https://leetcode.com/problems/path-sum-ii/

Problem Statement - Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where the sum of the node values in the path equals targetSum. Each path should be returned as a list of the node values, not node references.

A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no children.

Example

Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: [[5,4,11,2],[5,8,4,5]]
Explanation: There are two paths whose sum equals targetSum:
5 + 4 + 11 + 2 = 22
5 + 8 + 4 + 5 = 22

*/


class Solution 
{
public:
    // vector of vectors to store the final answer
    vector<vector<int>> ans;
    
    void sum(TreeNode* root, int targetSum, int s, vector<int> v)
    {
        if(root==NULL)
            return;
        
        // If the node is a leaf node, checking if target sum is reached
        if(root->left==NULL && root->right==NULL)
        {
            // if target sum is reached, pushing the vector in the vector of vectors
            if(s+root->val==targetSum)
            {
                v.push_back(root->val);
                ans.push_back(v);
            }
            return;
        }
        
        // If it's not a leaf node then storing it's value in vector
        s+=root->val;
        v.push_back(root->val);
        
        // calling the left sub-tree
        if(root->left)
            sum(root->left,targetSum,s,v);
        
        //calling the right sub-tree
        if(root->right)
            sum(root->right,targetSum,s,v);
        
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) 
    {
        vector<int> v;
        int s=0;
        
        sum(root,targetSum,s,v);
        
        return ans;
    }
};