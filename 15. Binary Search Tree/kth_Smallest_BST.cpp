/* Kth Smallest Number in BST */
/*
    For a BST and an integer k, 
    return the kth smallest value (1-indexed) of all the values 
    of the nodes in the tree.

    Approach:
    Simple Idea is to do a depth first search and store in an array and
    then print the final answer i.e. kth element.

    But the another widely used approach is by using BST Iterator
    which return the element until it has some elements in BST.

    Given code follow the method of BST Iterator
*/

#include<bits/stdc++.h>

using namespace std;

// Tree Structure
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int num)
    {
        val = num;
        left = NULL;
        right = NULL;
    }
 };


// Iterator Definition
class BST_Iterator {
        stack<TreeNode *>st;
    public:
        BST_Iterator(TreeNode* root) {
            pushUntil(root);
        }

        // pushes the BST on to stack
        void pushUntil(TreeNode *root)
        {
            while(root!=NULL)
            {
                st.push(root);
                root = root->left;
            }
        }

        // return the next value
        int next() {
            TreeNode *temp = st.top();
            st.pop();
            pushUntil(temp->right);
            return temp->val;
        }
        
        // check for available numbers
        bool hasNext() {
            return !st.empty();
        }
};


// simple code for insert BST
void insert(TreeNode* &root,int num)
{
    if(root == NULL)
        root = new TreeNode(num);
    else if(root->val > num)
        insert(root->left, num);
    else insert(root->right, num);
}

// Solution for the problem statement.
int kthSmallest(TreeNode* root, int k) {
    BST_Iterator it(root);  // creating object of BST Iterator
    k--;
    while(it.hasNext() && k)
    {
        it.next();
        k--;
    }
    return it.next();
}

int main()
{
    TreeNode *root = NULL;
    int n = 6;
    int nums[n] = {6, 1, 5, 4, 2, 3};


    // Tree insertion
    for(int i=0; i<n;i++)
        insert(root, nums[i]);

    // printing kth smallest element
    int k = 3;
    cout<<kthSmallest(root,k);
}
