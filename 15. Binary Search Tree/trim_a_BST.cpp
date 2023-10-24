/* PROBLEM STATEMENT
In Trim a Binary Search Tree problem we have given a binary search tree and a lower (as L) and higher bound (as R) of a range of integer values,
trim the BST so that all its elements lie in the range[L,R] (R >= L).If the given BST root value doesn’t lie in the range,then a new root witH
value in the given range is to be returned.
*/


#include <bits/stdc++.h>
using namespace std;

/* structure of a tree node */

class TreeNode
{
    public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int num)
    {
        data = num;
        left = right = NULL;
    }
};
/* function to trim the BST */

TreeNode *trimBST(TreeNode *root,int L,int R)
{
    if (root == NULL) 
    return root;

    root->left = trimBST(root->left,L,R);
    root->right = trimBST(root->right,L,R);

    if(root->data < L || root->data > R)
    {
        if(root->left == NULL)
        return root->right;

        if(root->right == NULL)
        return root->left;
    }

    return root;
}
/* function to perform inorder traversal of the BST */

static void inorder(TreeNode *root)
{
    if(root == NULL)
    return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main() 
{
    /* construct the BST */
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);

    cout<<"Inorder Traversal Without Trimming: ";
    inorder(root);

    /* define the upper and lower bound of the 
    ranges into which the BST needs to be trimmed */
    int L = 2;
    int R = 6;

    root = trimBST(root,L,R);
    cout<<endl;

    cout<<"Inorder Traversal After Trimming: ";
    inorder(root);
  return 0;
}
/*
Time Complexity: T(n) = O(n).
Space Complexity: S(n) = O(1).
*/
