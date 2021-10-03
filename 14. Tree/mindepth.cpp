#include <bits/stdc++.h>
using namespace std;

struct node {
	int data;
	struct node *left, *right;
};
struct node* newNode(int data);

int minDepth(node* root) {
        if(!root) return 0;
        int l = minDepth(root->left);
        int r = minDepth(root->right);
        return (l==0 || r==0)?(l+r+1) : (l>r?r:l)+1;
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
	cout << "Minimum depth of the given binary tree is " << minDepth(root);
	return 0;
}