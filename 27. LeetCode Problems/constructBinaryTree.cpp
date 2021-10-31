//Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int preindex = 0;
    TreeNode* build(vector<int>& preorder, vector<int>& inorder,int start,int end,unordered_map<int,int>&mp)
    {
        if(start > end)
            return NULL;
        
        
        TreeNode* root1 = new TreeNode(preorder[preindex]);
       
        int curr = mp[preorder[preindex++]];
        
        
        root1->left = build(preorder,inorder,start,curr-1,mp);
        root1->right = build(preorder,inorder,curr+1,end,mp);
        
        return root1;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        int start = 0;
        int end = n-1;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[inorder[i]] = i;
        }
        
        return build(preorder,inorder,start,end,mp);
       
    }
};