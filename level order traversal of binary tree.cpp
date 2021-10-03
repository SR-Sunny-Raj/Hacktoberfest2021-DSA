// Binary Tree is a tree in which each nodes can have atmost two childrens
//Level order traversal of a tree is breadth first traversal for a tree
//          1
//        /   \
//       2    3
//     /   \
//   4      5
// here level order traversal is -- 1 2 3 4 5

//It can be implemented using Recursion but time complexity will be O(n^2)
// so optimal approach is by using queue data structure

// code 

#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node*left;
    struct node*right;
// constructor
    node(int val){
        data=val;
        left=right=NULL;
    }
};

void levelorder(struct node*root){

    queue<struct node*> q; // creating an empty queue
    q.push(root);   // enqueue root

    if(root==NULL) return; //  base case

    while(!q.empty()){
        struct node*curr=q.front();
        q.pop();
        cout<<curr->data<<" ";  // printing front of queue

        if(curr->left!=NULL) q.push(curr->left);   // enqueue left child

        if (curr->right!=NULL) q.push(curr->right);  // enqueue right child
    }

  return;
}

// driver program
int main() 
{  
 struct node*root= new node(1);
 root->left= new node(2);
 root->right=new node(7);
 root->left->left=new node(3);
 root->left->right= new node(4);
 root->left->right->left= new node(5);
 root->left->right->right= new node(6);

levelorder(root);
return 0;
}

// time complexity ---O(n)    where n is number of nodes in a tree 
// space complexity ---O(n)
