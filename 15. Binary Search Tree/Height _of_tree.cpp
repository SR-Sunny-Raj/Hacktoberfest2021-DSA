#include <iostream>
using namespace std;

struct Node
{
    int key;
    Node *left, *right;

    Node(int key)
    {
        this->key = key;
        this->left = this->right = NULL;
    }
};

// Recursive function to calculate height of given binary tree
int height(Node* root)
{
    // Base case: empty tree has height 0
    if (root == NULL)
        return 0;

    // recur for left and right subtree and consider maximum depth
    return 1 + max(height(root->left), height(root->right));
}

// main function
int main()
{
    Node* root = NULL;
    
    root = new Node(10);
    root->left = new Node(1);
    root->right = new Node(12);
    root->left->left = new Node(29);
    root->left->right = new Node(35);
    root->right->left = new Node(55);
    root->right->right = new Node(20);

    cout << "The height of the binary tree is " << height(root);

    return 0;
}
