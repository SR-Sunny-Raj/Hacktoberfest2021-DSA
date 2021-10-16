/*
Given a Binary Tree, print the diagonal traversal of the binary tree.

Consider lines of slope -1 passing between nodes. Given a Binary Tree, print all diagonal elements in a binary tree belonging to same line.


Input:
8 3 10 1 6 N 14 N N 4 7 13


Output: 
8 10 14 3 6 7 13 1 4 

you can go through the question
https://www.geeksforgeeks.org/diagonal-traversal-of-binary-tree/

Here we use a queue to solve diagonal traversal problem . 
The logic used here is to level order traversal but instead of storing nodes of a level, we enqueue nodes in a diagonal.

*/

/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */


vector<int> diagonal(Node *root)
{
    queue<Node*> q;
    vector<int> ans;
    if(!root) return ans;
    q.push(root);
    while(!q.empty()){
        Node* x = q.front();
        q.pop();
        while(x){
            if(x->left) q.push(x->left);
            ans.push_back(x->data);
            x = x->right;
        }
        
    }
return ans;
}
