
// Program to implement RedBlack Tree

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

typedef struct node
{
    int key;
    int color;
    struct node *left;
    struct node *right;
}*node;

typedef struct tree
{
    node root;
}*tree;

node CreateNode(int);
node InsertRedBlack(node,int);
node insertrbtree(node,node);
node RotateFromLeft(node);
node RotateFromRight(node);
void PrintTree(tree);

int main()
{
    char c;
    int key;
    tree t = (tree) malloc(sizeof(tree));
    node sentinel = (node) malloc(sizeof(node));
    sentinel = CreateNode(-1);
    t->root = sentinel;
    
    while(1)
    {
        if(scanf("%d",&key)!=1)
            return 0;
        t->root = InsertRedBlack(t->root, key);
    }
}

node CreateNode(int k)
{
    node x = (node) malloc(sizeof(struct node));
    x->key = k;
    x->color = 0;
    x->left = NULL;
    x->right = NULL;
    return x;
}

node InsertRedBlack(node root, int key)
{
    tree temp = (tree) malloc(sizeof(tree));
    node sentinel = (node) malloc(sizeof(node));
    sentinel = CreateNode(-1);
    //temp->root = root;
    node x = CreateNode(key);
    x->right = x->left = sentinel;
    x->color = 1;
    temp->root = insertrbtree(root,x);
    if(temp->root->color = 1)
        temp->root->color = 0;
    PrintTree(temp);
    printf("\n");
    return temp->root;
}

node insertrbtree(node r, node x)
{
    
    if(r->key < 0)
        return x;
    else if(r->key < x->key)
    {
        r->right = insertrbtree(r->right,x);
        if(r->right->color == 1)
        {
            if(r->right->right->color == 1 || r->right->left->color == 1)
            {
                if(r->left->color == 1)
                {
                    //case 1
                    r->right->color = 0;
                    r->left->color = 0;
                    r->color = 1;
                    return r;
                }
                else
                {
                    //case 3 converted to case 2 
                    if(r->right->left->color == 1)
                        r->right = RotateFromLeft(r->right);
                    //case 2
                    node y = (node) malloc(sizeof(node));
                    y = r->right;
                    y = RotateFromRight(r);
                    y->left->color = 1;
                    y->color = 0;
                    return y;
                }
            }
        }
        else
            return r;
    }
    else
    {
        r->left = insertrbtree(r->left,x);
        if(r->left->color == 1)
        {
            if(r->left->right->color == 1 || r->left->left->color == 1)
            {
                if(r->right->color == 1)
                {
                    // case 1
                    r->right->color = 0;
                    r->left->color = 0;
                    r->color = 1;
                    return r;
                }
                else
                {
                     //case 3 converted to case 2 
                    if(r->left->right->color == 1)
                        r->left = RotateFromRight(r->left);
                    //case 2
                    node y = (node) malloc(sizeof(node));
                    y = r->left;
                    y = RotateFromLeft(r);
                    y->right->color = 1;
                    y->color = 0;
                    return y;
                }
            }
        }
    }
    return r;
}

node RotateFromLeft(node n)
{
    node p = (node) malloc(sizeof(node));
    p = n->left;
    n->left = p->right;
    p->right = n;
    return p;
}

node RotateFromRight(node n)
{
    node p = (node) malloc(sizeof(node));
    p = n->right;
    n->right = p->left;
    p->left = n;
    return p;
}

void PrintTree(tree t)
{
    if(t->root->key > -1)
    {
        printf("( ");
        if(t->root->color == 1)
            printf("%d R ",t->root->key);
        else
            printf("%d B ",t->root->key);

        tree temp = (tree)  malloc(sizeof(struct tree));
        temp->root = t->root->left;
        PrintTree(temp);
        temp->root = t->root->right;
        PrintTree(temp);
        printf(") ");
    }
    else
        printf("( ) ");
}