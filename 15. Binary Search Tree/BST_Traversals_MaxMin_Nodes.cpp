#include <iostream>

using namespace std;

struct BST{
	int data;
	struct BST *left;
	struct BST *right;
	struct BST *parent;
};
typedef struct BST node;
node *root = NULL, *temp;

int main(){
	int choice;
	void insert();
	void inorder(node *);
	void preorder(node *);
	void postorder(node *);
	void findmin(node *);
	void findmax(node *);
	void find(node *);
	void successor(node *);
	void deletenode(node *);
	do{
		cout<<endl;
		cout<<"1) Insert"<<endl;
		cout<<"2) inorder"<<endl;
		cout<<"3) preorder"<<endl;
		cout<<"4) postorder"<<endl;
		cout<<"5) Find Mininmum"<<endl;
		cout<<"6) Find Maximum"<<endl;
		cout<<"7) Find Number"<<endl;
		cout<<"8) Find Successor"<<endl;
		cout<<"9) Delete a node"<<endl;
		cout<<"10) Exit"<<endl;
		cout<<"Enter your choice: ";
		cin>>choice;
		switch(choice){
			case 1: insert();
				break;
			case 2: inorder(root);
				break;
			case 3: preorder(root);
				break;
			case 4: postorder(root);
				break;
			case 5: findmin(root);
				break;
			case 6: findmax(root);
				break;
			case 7: find(root);
				break;
			case 8: successor(root);
				break;
			case 9: deletenode(root);
				break;
			case 10: break;
		}
	}while(choice != 10);
	return 0;
}
void create(); //simply create a node
void search(node *);
void insert(){	
		create();
		if(root == NULL)
			root=temp;
		else{
			search(root);
		}
	
}

void create(){
	int element;
	cout<<"Enter the element: ";
	cin>>element;
	temp=new node;
	temp->data = element;
	temp->left = NULL;
	temp->right = NULL;
	temp->parent = NULL;
}

void search(node *r){
	if(temp->data < r->data && r->left== NULL){
		r->left = temp;
		temp->parent = r;
	}
	
	else if(temp->data < r->data && r->left!= NULL)
		search(r->left);
	
	else if(temp->data > r->data && r->right== NULL){
		r->right = temp;
		temp->parent = r;
	}
	
	else if(temp->data > r->data && r->right!= NULL)
		search(r->right);
}

void inorder(node *t){
	if(t != NULL){
		inorder(t->left);
		cout<<" "<<t->data;
		inorder(t->right);
	}
}

void preorder(node *t){
	if(t != NULL){
		cout<<" "<<t->data;
		preorder(t->left);
		preorder(t->right);
	}
}

void postorder(node *t){
	if(t != NULL){
		postorder(t->left);
		postorder(t->right);
		cout<<" "<<t->data;
	}
}

void findmin(node *t){
	if(t != NULL){
		while(t->left != NULL){
			t = t->left;
		}
		cout<<t->data<<endl;
	}
}

void findmax(node *t){
	if(t != NULL){
		while(t->right != NULL){
			t = t->right;
		}
		cout<<t->data<<endl;
	}
}

void find(node *t){
	int k;
	cout<<"Enter the number to search: ";
	cin>>k;
	while(t != NULL && k != t->data){
		if(k < t->data)
			t = t->left;
		else
			t = t->right;
	}
	if(t == NULL)
		cout<<k<<" is not found"<<endl;
	else
		cout<<k<<" found"<<endl;
}

void successor(node *t){
	int k;
	cout<<"Enter the number for which you want to find successor: ";
	cin>>k;
	node *x = t;
	if(t != NULL)
	{
		while(x->right != NULL)
		{
			x = x->right;
		}
		while(t != NULL && k != t->data)
		{
			if(k < t->data)
				t = t->left;
			else
				t = t->right;
		}
		if(t->right != NULL)
		{
			findmin(t->right);
			
		}
		else if(t == x)
		{
			cout<<"No Successor"<<endl;
		}
		else
		{
			node *p = t->parent;
			while(p != NULL && t == p->right)
			{
				t = p;
				p = p->parent;
			}
	    	cout<<p->data<<endl;
		}
	}
}
void deleteleaf(node *x);
void delete2childnode(node *x);
void delete1childnode(node *x);
void deletenode(node *t){
	
	int k;
	cout<<"Enter the number to delete: ";
	cin>>k;
	if(t != NULL){
		while(t != NULL && k != t->data){
			if(k < t->data)
				t = t->left;
			else
				t = t->right;
		}
		if(t == NULL)
			cout<<k<<" does not exist"<<endl;
		else{
			if(t->left == NULL && t->right == NULL)
			{ //leaf node condition
				deleteleaf(t);
			}
			else if(t->left != NULL && t->right != NULL)
			{ //node with both children
				delete2childnode(t);
			}
			else if(t->left != NULL || t->right != NULL)
			{ //node with one child
				delete1childnode(t);
			}
		}
	}
}

void deleteleaf(node *x){
	if(x->parent->left == x)
		x->parent->left = NULL;
	else
		x->parent->right = NULL;
}

void delete1childnode(node *x){
	if(x->parent->left == x){
		if(x->left == NULL){
			x->right->parent = x->parent;
			x->parent->left = x->right;
		}else{
			x->left->parent = x->parent;
			x->parent->left = x->left;
		}
	}
	else{
		if(x->left == NULL)
		{
			x->right->parent = x->parent;
			x->parent->right = x->right;
		}
		else
		{
			x->left->parent = x->parent;
			x->parent->right = x->left;
		}
	}
}

void delete2childnode(node *x){
	node *t = x->right;
	if(t != NULL)
	{
		while(t->left != NULL)
		{
			t = t->left;
		}
		x->data = t->data;
		if(t->right == NULL){
			deleteleaf(t);
		}else{
			delete1childnode(t);
		}
	}
}
