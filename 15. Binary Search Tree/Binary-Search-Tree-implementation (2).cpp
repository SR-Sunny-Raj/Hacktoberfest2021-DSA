#include<iostream>
using namespace std;

struct Node{
	int data;
	Node* left;
	Node* right;
};

Node* Insert(Node*root, int value)
{
	if(root == NULL)
		{
			Node* temp = new Node;
			temp->data = value;
			temp->left = NULL;
			temp->right = NULL;
			return temp;
		}
		else if(root->data > value){
			root->left = Insert(root->left, value);
		}
			else if(root->data < value){
				root->right= Insert(root->right, value);
			}
		return root;	
	
	}

int findHeight(Node*root){
	if(root == NULL){
	return -1;
	}
	else if(findHeight(root->left) > findHeight(root->right)){
		return findHeight(root->left)+1;
	}
	else{
		return findHeight(root->right)+1;
	}
	
}
	
int main(){
	Node* root = NULL;
	root = Insert(root, 15); 
	root = Insert(root, 14);
	root = Insert(root, 23);
	root = Insert(root, 8);

	int max;
	max = findHeight(root);
	cout<<"The height of tree is: "<<max;
}
