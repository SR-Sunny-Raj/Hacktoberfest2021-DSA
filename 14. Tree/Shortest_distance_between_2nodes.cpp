#include <bits/stdc++.h>
#include <iostream>
using namespace std;

typedef long long ll;
typedef long long unsigned llu;

struct Node
{
    int data;
    struct Node *left, *right;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

// LCA method  (Time Complexity --> O(n) and Space Complexity --> O(1))

Node *LCA(Node *root, int n1, int n2)
{
    if (root == NULL)
        return NULL;

    if (root->data == n1 || root->data == n2)
        return root;

    Node *left = LCA(root->left, n1, n2);   //  Now we will find out LCA in the left subtree
    Node *right = LCA(root->right, n1, n2); // similarly for the right.

    if (left != NULL && right != NULL) // we get n1 or n2 from left or right.
        return root;

    if (left == NULL && right == NULL)
        return NULL;

    if (left != NULL)
        return LCA(root->left, n1, n2);

    return LCA(root->right, n1, n2);
}

int findDist(Node *root, int k, int dist)
{
    if (root == NULL)
        return -1;

    if (root->data == k)
        return dist;

    int left = findDist(root->left, k, dist + 1);
    if (left != -1)
        return left;

    return findDist(root->right, k, dist + 1);
}

int distBtwNodes(Node *root, int n1, int n2)
{
    Node *lca = LCA(root, n1, n2);

    int d1 = findDist(lca, n1, 0);
    int d2 = findDist(lca, n2, 0);

    return d1 + d2;
}

int main()
{
    Node *root = new Node(25);

    root->left = new Node(15);
    root->left->right = new Node(22);
    root->left->left = new Node(10);
    root->right = new Node(30);
    root->right->left = new Node(28);
    root->right->right = new Node(33);

    cout << distBtwNodes(root, 22, 28);
    return 0;
}