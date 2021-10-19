#include <bits/stdc++.h>
using namespace std;
 
// tree node has three components -> data, left child, and right child
struct Node {
 
    int data;
    Node *left, *right;
};
 
// Helper function to create the new node with provided data
Node* newNode(int data)
{
    Node* node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return node;
}
// An iterative function to do postorder traversal
// of a given binary tree
void postOrderIterative(Node* root)
{
    // return if tree is empty 
    if (root == NULL)
        return;
 
    // Create two stacks
    stack<Node *> s1;
    stack<Node *>s2;
 
    // push root to the first stack
    s1.push(root);
    // create the new node named current
    Node* current;
 
    // Loop until first stack becomes empty
    while (!s1.empty()) {
        // Pop an item from s1(stack1) and push it to s2(stack2)
        current = s1.top();
        s1.pop();
        s2.push(current);
 
        // Push left and right children
        // of popped item to s1
        if (current->left)
            s1.push(current->left);
        if (current->right)
            s1.push(current->right);
    }
 
    // Print the elements of stack2 until it becomes empty
    while (!s2.empty()) {
        current = s2.top();
        s2.pop();
        cout << current->data << " ";
    }
}
int main()
{
    // Construct the below figure
    /*
                1
              /   \
             /     \
            2       3
           / \     /
          /   \   /
         4     5 6
    */
    Node* root = NULL;
    root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
 
    postOrderIterative(root);
 
    return 0;
}
