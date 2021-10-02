#include <bits/stdc++.h>
using namespace std;

// Data structure to store a Binary Search Tree node
struct Node
{
	int data;
	Node *left, *right;
};

// Function to create a new binary tree node having given key
Node* newNode(int key)
{
	Node* node = new Node;
	node->data = key;
	node->left = node->right = NULL;

	return node;
}

// Recursive function to insert a key into BST
Node* insert(Node* root, int key)
{
	// if the root is null, create a new node and return it
	if (root == NULL)
		return newNode(key);
		
	if (key == root->data) 
    { 
        return root; 
    } 

	// if given key is less than the root node, recur for left subtree
	if (key < root->data)
		root->left = insert(root->left, key);

	// if given key is more than the root node, recur for right subtree
	else
		root->right = insert(root->right, key);

	return root;
}

bool find(Node *root, int data){
    if(root == NULL){
      return false;
    }

    if(data >root->data){
      return find(root->right, data);
    } else if(data < root->data){
      return find(root->left, data);
    } else {
      return true;
    }
  }  
  
void targetSumPair(Node *root, Node *node, int tar) {
    if (node == NULL) {
      return;
    }

    targetSumPair(root, node->left, tar);

    int comp = tar - node->data;
    if (comp > node->data) {
      if (find(root, comp)) {
        cout<<node->data<<" "<<comp<<endl;
      }
    }
    
    targetSumPair(root, node->right, tar);
  }

int main()
{
	Node* root = NULL;
	int n;cin>>n;
	for(int i=0;i<n;i++)
    {
         string a;
        cin>>a;
        
        if(a!="n")
        {
            int w=stoi(a);
           
    root = insert(root,w);
        }
    }
    int data;cin>>data;
    targetSumPair(root, root, data);
	return 0;
}
