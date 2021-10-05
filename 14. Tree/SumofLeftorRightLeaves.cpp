/*
Given the root of a binary tree, return the sum of all left leaves.
For example - 1
             / \
            4   5
           / \ / \
          6  7 8  9
Sum of left leaves = 6 + 8 = 14
In an interview they may even ask you for sum of right leaves
sum of right leaves = 7 + 9 = 16

You can also try the problem here on leetcode
https://leetcode.com/problems/sum-of-left-leaves/
This question was asked in SAP LABS
*/

#include<bits/stdc++.h>
using namespace std;

//Structure of tree
struct TreeNode{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x){
        val = x;
        left = right = NULL;
    }
};

//this function gives you sum of leaves according to the 
//flag you pass to them, here i have taken a flag = 1
//for all left leaves, similarly for sum of right leaves
//you can pass 1 on right function call and 0 on left call


// Time Complexity - O(N) N = No. of nodes in tree
// Space Complexity - O(1)
int sumofleaves(TreeNode* node,int flag){
    if(node == NULL)
        return 0;
    //if we reach the left leaf node
    //here flag helps us determine that this is indeed left leaf node
    if(node->left == NULL && node->right == NULL && flag){
        return node->val;
    }
    //calling recursively throughout the tree
    //for right leaves just pass 0 in left call
    // and 1 in right call
    return sumofleaves(node->left,1) + sumofleaves(node->right,0);
}


int main(){
    // Constructing our above example binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(4);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(7);
    root->right->left = new TreeNode(8);
    root->right->right = new TreeNode(9);

    //passing 0 flag as root is not a leaf node
    cout << sumofleaves(root,0) << endl;
    
    //Outputs 14

    return 0;
}
