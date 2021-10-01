#include<iostream>
using namespace std;

struct Node{
  int data;
  Node* left;
  Node* right;

  Node(int val){
      data=val;
      left=NULL;
      right=NULL;
  }  
};

Node* searchInBST(Node* root,int val){
    if(root==NULL){
        return NULL;
    }
    if(root->data==val){
        return root;
    }
    else if(root->data>val){
        return searchInBST(root->left,val);
    }
    else{
        return searchInBST(root->right,val);
    }
}

int main(){

    Node* root=new Node(4);
    root->left=new Node(2);
    root->right=new Node(5);
    root->left->left=new Node(1);
    root->left->right=new Node(3);
    root->right->right=new Node(6);

    if(searchInBST(root,3)==NULL){
        cout<<"num not found"<<endl;
    }
    else{
        cout<<"num is present";
    }
    

    return 0;
}