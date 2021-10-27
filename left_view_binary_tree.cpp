#include <iostream>
using namespace std;
 
struct Node
{
    int key;
    Node *left, *right;
 
    Node(int key)
    {
        this->key = key;
        this->left = this->right = nullptr;
    }
};
 
void leftView(Node* root, int level, int &last_level)
{
    if (root == nullptr) {
        return;
    }
 
    if (last_level < level)
    {
        cout << root->key << " ";
 
        last_level = level;
    }
 
    leftView(root->left, level + 1, last_level);
    leftView(root->right, level + 1, last_level);
}
 
void leftView(Node* root)
{
    int last_level = 0;
    leftView(root, 1, last_level);
}
 
int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);
    root->right->left->right = new Node(8);
 
    leftView(root);
 
    return 0;
}
