#include<iostream>
using namespace std;
#include<queue>
template <typename t>
class binarytree{
	public:
		t data;
		binarytree* left;
		binarytree* right;
		binarytree(t data)
		{
			this->data=data;
			left=NULL;
			right=NULL;
		}
		~binarytree()
		{
			delete left;
			delete right;
		}
		
};
class bst{
	private:
		binarytree<int>* root;
	public:
		bst()
		{
			root=NULL;
		}
		~bst()
		{
			delete root; 
		}
		private:
			binarytree<int>* inserthelp(int data,binarytree<int>* root)
			{
				if(root==NULL)
				{
					binarytree<int>* n1= new binarytree<int>(data);
					return n1;
				}
				
				if(root->data>data)
				{
					root->left = inserthelp(data,root->left);
				}
				else
				{
					root->right=inserthelp(data,root->right);
				}
				return root;
			}
		public:
		void insert(int data)
		{
			this->root=inserthelp(data,this->root);
		}
		private:
			void print(binarytree<int>* root)
			{
				queue<binarytree<int>*> q;
				q.push(root);
				while(q.size()!=0)
			{
			binarytree<int>* front=q.front();
			q.pop();
			cout<<front->data<<":";
			if(front->left!=NULL)
			{
			cout<<"L"<<front->left->data;
			q.push(front->left);
			}
			
			if(front->right)
			{
			cout<<"R"<<front->right->data;
			q.push(front->right);
			}
			cout<<endl;
			}
			}
			public:
				void printtree()
				{
					print(root);
				}
};
binarytree<int>* input2()
{
	queue<binarytree<int>*> q;
	int rdata;
	cout<<"Enter data"<<endl;
	cin>>rdata;
	binarytree<int>* root=new binarytree<int>(rdata);
	q.push(root);
	while(q.size()!=0)
	{
		binarytree<int>* front=q.front();
		q.pop();
		cout<<"Enter left child of "<<front->data<<endl;
		int leftchild;
		cin>>leftchild;
		if(leftchild!=-1)
		{
			binarytree<int>* n=new binarytree<int>(leftchild);
			front->left=n;
			q.push(n);
		} 
		
		cout<<"Enter right child of "<<front->data<<endl;
		int rightchild;
		cin>>rightchild;
		if(rightchild!=-1)
		{
			binarytree<int>* n=new binarytree<int>(rightchild);
			front->right=n;
			q.push(n);
		}
	}
	return root;
}
void print(binarytree<int>* root)
{
	queue<binarytree<int>*> q;
	q.push(root);
	while(q.size()!=0)
	{
		binarytree<int>* front=q.front();
		q.pop();
		cout<<front->data<<":";
		if(front->left!=NULL)
		{
			cout<<"L"<<front->left->data;
			q.push(front->left);
		}
		
		if(front->right)
		{
			cout<<"R"<<front->right->data;
			q.push(front->right);
		}
		cout<<endl;
	} 
}
int main()
{
	bst p;
	p.insert(4);
	p.insert(2);
	p.insert(6);
	p.insert(1);
	p.insert(3);
	p.insert(5);
	p.insert(7);
	p.printtree();
	cout<<endl;
	return 0;
}
