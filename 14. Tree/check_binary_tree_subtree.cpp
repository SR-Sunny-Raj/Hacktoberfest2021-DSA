// C++ program to check if binary tree
// is subtree of another binary tree
#include<bits/stdc++.h>
using namespace std;

/* A binary tree node has data,
left child and right child */
class node
{
	public:
	int data;
	node* left;
	node* right;
};

/* A utility function to check
whether trees with roots as root1 and
root2 are identical or not */
bool areIdentical(node * root1, node *root2)
{
	/* base cases */
	if (root1 == NULL && root2 == NULL)
		return true;

	if (root1 == NULL || root2 == NULL)
		return false;

	/* Check if the data of both roots is
	same and data of left and right
	subtrees are also same */
	return (root1->data == root2->data &&
			areIdentical(root1->left, root2->left) &&
			areIdentical(root1->right, root2->right) );
}


/* This function returns true if S
is a subtree of T, otherwise false */
bool isSubtree(node *T, node *S)
{
	/* base cases */
	if (S == NULL)
		return true;

	if (T == NULL)
		return false;

	/* Check the tree with root as current node */
	if (areIdentical(T, S))
		return true;

	/* If the tree with root as current
	node doesn't match then try left
	and right subtrees one by one */
	return isSubtree(T->left, S) ||
		isSubtree(T->right, S);
}


/* Helper function that allocates
a new node with the given data
and NULL left and right pointers. */
node* newNode(int data)
{
	node* Node = new node();
	Node->data = data;
	Node->left = NULL;
	Node->right = NULL;
	return(Node);
}

/* Driver code*/
int main()
{
	// TREE 1
	/* Construct the following tree
			26
			/ \
		10 3
		/ \ \
	4 6 3
	\
		30
	*/
	node *T = newNode(26);
	T->right		 = newNode(3);
	T->right->right = newNode(3);
	T->left		 = newNode(10);
	T->left->left	 = newNode(4);
	T->left->left->right = newNode(30);
	T->left->right	 = newNode(6);

	// TREE 2
	/* Construct the following tree
		10
		/ \
	4 6
	\
		30
	*/
	node *S = newNode(10);
	S->right	 = newNode(6);
	S->left	 = newNode(4);
	S->left->right = newNode(30);


	if (isSubtree(T, S))
		cout << "Tree 2 is subtree of Tree 1";
	else
		cout << "Tree 2 is not a subtree of Tree 1";

	return 0;
}

// This code is contributed by rathbhupendra
