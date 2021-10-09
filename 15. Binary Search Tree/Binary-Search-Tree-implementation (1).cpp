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
bool Search(Node* root, int value){
	if(root == NULL){
		return false;
	}
	else if(root->data == value){
		return true;
	}
	else if(value <= root->data){
		return Search(root->left, value);
	}
	else if(value >= root->data){
		return Search(root->right, value);
	}
}
Node* search(Node* root, int value){
	if(root == NULL){
	cout<<"TREE IS EMPTY";
	}
	else if(root->data == value){
		return root;
	}
	else if(value <= root->data){
		return search(root->left, value);
	}
	else if(value >= root->data){
		return search(root->right, value);
	}
	
}
Node* Update(Node* root, int value, int newvalue){
	Node* temp= NULL;
	temp = search(root, value);
	temp->data = newvalue;
	return temp;
}



int main(){
	Node* root = NULL;
	root = Insert(root, 15); 
	root = Insert(root, 14);
	root = Insert(root, 23);
	root = Insert(root, 8);
	int number;
	int update;
	cout<<"Enter number be searched \n";
	cin>>number;
	if(Search(root, number)==true){
		cout<<"found! \n";
	}
		else{
			cout<<"Not Found! \n";
		}
	cout<<"Enter number be updated \n";
	cin>>number;
		if(Search(root, number)==true){
		cout<<"Enter the number to put at the searched place!"<<endl;
	cin>>update;
  	root = Update(root, number, update);
  }
		else{
			cout<<"Not Found! \n";
		}

	
	

	
}	

