#include <iostream>
using namespace std;

struct Node
{
	struct Node *left, *right;
	int key;
};

Node* newNode(int key)
{
	Node *temp = new Node;
	temp->key = key;
	temp->left = temp->right = NULL;
	return temp;
}
int findlevel(Node *root, int k, int level)
{
	if (root == NULL)
		return -1;

	if (root->key == k)
		return level;

	int l = findlevel(root->left, k, level+1);
	return (l != -1)? l : findlevel(root->right, k, level+1);
}

Node *findDist(Node* root, int n1, int n2, int &d1,
							int &d2, int &dist, int lvl)
{
	if (root == NULL) return NULL;
	if (root->key == n1)
	{
		d1 = lvl;
		return root;
	}
	if (root->key == n2)
	{
		d2 = lvl;
		return root;
	}
	Node *left_lca = findDist(root->left, n1, n2,
								d1, d2, dist, lvl+1);
	Node *right_lca = findDist(root->right, n1, n2,
								d1, d2, dist, lvl+1);

	if (left_lca && right_lca)
	{
		dist = d1 + d2 - 2*lvl;
		return root;
	}
	return (left_lca != NULL)? left_lca: right_lca;
}

int findDistances(Node *root, int n1, int n2)
{
	int d1 = -1, d2 = -1, dist;
	Node *lca = findDist(root, n1, n2, d1, d2,
										dist, 1);

	if (d1 != -1 && d2 != -1)
		return dist;

	if (d1 != -1)
	{
		dist = findlevel(lca, n2, 0);
		return dist;
	}
	if (d2 != -1)
	{
		dist = findlevel(lca, n1, 0);
		return dist;
	}

	return -1;
}

int main()
{
    Node * root = newNode(20);
    root->left = newNode(10);
    root->right = newNode(30);
    root->left->left = newNode(5);
    root->left->right = newNode(15);
    root->right->left = newNode(25);
    root->right->right = newNode(35);
    cout << "Distance between 5 and 15 = " << findDistances(root, 5, 15);
    cout << "\nDistance between 5 and 25 = " << findDistances(root, 5, 25);
    cout << "\nDistance between 30 and 5 = " << findDistances(root, 30, 5);
    cout << "\nDistance between 10 and 5 = " << findDistances(root, 10, 5);
	return 0;
}
