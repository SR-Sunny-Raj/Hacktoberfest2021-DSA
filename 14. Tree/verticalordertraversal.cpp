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
    int left = 0, right = 0;
    
    int heightTree(TreeNode* root, int col)
    {
        if(!root) return 0;
        
        if(left > col) left = col;
        if(right < col) right = col;
        
        int leftSide = heightTree(root->left, col - 1);
        int rightSide = heightTree(root->right, col + 1);
        
        return max(leftSide,rightSide) + 1;
    }
    
    void traversal(TreeNode* root, int col, int row, vector<vector<vector<int> > >& grid)
    {
        if(!root) return;
        
        grid[row][col].push_back(root->val);
        
        traversal(root->left, col - 1, row + 1, grid);
        traversal(root->right, col + 1, row + 1, grid);
    }
    
    
    vector<vector<int> > verticalTraversal(TreeNode* root) 
    {
        if(!root) return { {} };
        
        int height = heightTree(root, 0);
        int width = right - left + 1;
        
        vector<vector<vector<int> > > grid(height, vector<vector<int> >(width));
        vector<vector<int> > ans;
        
        traversal(root, 0 - left, 0, grid);
        
        for(int col = 0; col < width; col++)
        {
            vector<int> temp;
            
            for(int row = 0; row < height; row++)
            {
                if(grid[row][col].size() > 1) 
                    sort(grid[row][col].begin(), grid[row][col].end());
                
                if(grid[row][col].size() > 0)
                    
                    for(int idx = 0; idx < grid[row][col].size(); idx++)
                        temp.push_back(grid[row][col][idx]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};