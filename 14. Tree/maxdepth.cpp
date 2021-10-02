#include <bits/stdc++.h>
using namespace std;

struct node {
	int data;
	struct node *left, *right;
};
struct node* newNode(int data);

int maxDepth(node* root) {
        if(!root) return 0;
        int l = maxDepth(root->left);
        int r = maxDepth(root->right);
        return 1+max(l,r);
}

struct node* newNode(int data)
{
	struct node* node = (struct node*)malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return (node);
}

// Driver Code
int main()
{
	struct node* root = newNode(3);
	root->left = newNode(9);
	root->right = newNode(20);
	root->right->left = newNode(15);
	root->right->right = newNode(7);
	cout << "Maximum depth of the given binary tree is " << maxDepth(root);
	return 0;
}