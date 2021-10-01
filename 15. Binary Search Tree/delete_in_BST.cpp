#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* right;
    Node* left;

    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

/*
         4
       /   \
      2     5
     / \     \
    1   3     6
*/

Node* inordersucc(Node* root){
    Node* curr=root;
    while(curr && curr->left !=NULL){
        curr=curr->left;
    }
    return curr;
}

Node* deleteInBST(Node* root,int val){

    if(root->data>val){
        root->left=deleteInBST(root->left,val);
    }
    else if(root->data<val){
        root->right=deleteInBST(root->right,val);
    }
    else{
        if(root->left==NULL){
            Node* temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL){
            Node* temp=root->left;
            free(root);
            return temp;
        }

        Node* temp=inordersucc(root->right);
        root->data = temp->data;
        root->right=deleteInBST(root->right,temp->data);
    }
    return root;
}

void inorder(Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(){

    Node* root=new Node(4);
    root->left=new Node(2);
    root->right=new Node(5);
    root->left->left=new Node(1);
    root->left->right=new Node(3);
    root->right->right=new Node(6);

    inorder(root);
    cout<<endl;
    root=deleteInBST(root,3);
    inorder(root);

    return 0;
}

//425136