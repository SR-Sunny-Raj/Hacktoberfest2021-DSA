// write program for getting preorder,postorder,inorder tree traversal of tree in both iterative as well as recursive manner

//time complexity for all recursive functions is O(n)
// time complexity of all iterative functions is also O(n)
#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
    Node(int data = 0)
    {
        this->data = data;
        left = right = NULL;
    }
};
class stack
{
public:
    struct Node *data;
    stack *next;
};

stack *insert(stack *top, Node *add)
{
    stack *s = new stack();
    s->data = add;
    if (top == NULL)
    {
        s->next = NULL;
        top = s;
        return top;
    }

    s->next = top;
    top = s;
    return top;
}
Node *pop(stack *&top)
{
    if (top == NULL)
    {
        return NULL;
    }
    stack *curr = new stack();
    curr = top;
    Node *tmp = curr->data;
    top = top->next;
    free(curr);
    return tmp;
}
void rprintPostorder(struct Node *node)
{
    if (node == NULL)
        return;

    // first recur on left subtree
    rprintPostorder(node->left);

    // then recur on right subtree
    rprintPostorder(node->right);

    // now deal with the node
    cout << node->data << " ";
}

/* Given a binary tree, print its nodes in inorder*/
void rprintInorder(struct Node *node)
{
    if (node == NULL)
        return;

    /* first recur on left child */
    rprintInorder(node->left);

    /* then print the data of node */
    cout << node->data << " ";

    /* now recur on right child */
    rprintInorder(node->right);
}

/* Given a binary tree, print its nodes in preorder*/
void rprintPreorder(struct Node *node)
{
    if (node == NULL)
        return;

    /* first print data of node */
    cout << node->data << " ";

    /* then recur on left sutree */
    rprintPreorder(node->left);

    /* now recur on right subtree */
    rprintPreorder(node->right);
}

void printInorder(Node *root)
{
    if (root == NULL)
    {
        cout << "empty";
        return;
    }
    stack *top = NULL;
    Node *p = root;
    while (p != NULL || top != NULL)
    {
        if (p != NULL)
        { /* Reach the left most Node of the
            curr Node */
            top = insert(top, p);
            p = p->left;
        }
        else
        {
            p = pop(top);
            cout << p->data << " ";
            p = p->right;
        }
    }
    return;
}
void printPreorder(Node *root)
{
    if (root == NULL)
    {
        cout << "empty";
        return;
    }
    stack *top = NULL;
    //insertion in stack
    top = insert(top, root);
    Node *p;
    while (top != NULL)
    {
        p = pop(top);
        cout << p->data << " ";
        /* Reach the left most Node of the
            curr Node */
        if (p->right != NULL)
        {
            top = insert(top, p->right);
        }
        if (p->left != NULL)
        {
            top = insert(top, p->left);
        }
    }

    return;
}
void printPostorder(Node *root)
{
    if (root == NULL)
    {
        cout << "empty";
        return;
    }
    Node *p;
    stack *top1 = NULL;
    top1 = insert(top1, root);
    stack *top2 = NULL;
    while (top1 != NULL)
    {
        p = pop(top1);
        top2 = insert(top2, p);
        if (p->left != NULL)
        {
            top1 = insert(top1, p->left);
        }
        if (p->right != NULL)
        {
            top1 = insert(top1, p->right);
        }
    }
    while (top2 != NULL)
    {
        p = pop(top2);
        cout << p->data << " ";
    }
}
int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    cout << "Output of recursion call:\n ";
    cout << "\nInorder traversal of binary tree is \n";
    rprintInorder(root);
    cout << "\nPreorder traversal of binary tree is \n";
    rprintPreorder(root);
    cout << "\nPostorder traversal of binary tree is \n";
    rprintPostorder(root);

    cout << "\n\nIterative output: \n";
    cout << "\nPreorder traversal of binary tree is \n";
    printPreorder(root);
    cout << "\nInorder traversal of binary tree is \n";
    printInorder(root);
    cout << "\nPostorder traversal of binary tree is \n";
    printPostorder(root);
    return 0;
}
