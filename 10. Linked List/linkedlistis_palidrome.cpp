//Check whether Singly Linked List is a Palindrome or Not//
#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
        next = NULL;
    }
};
node *takeinput_better()
{
    int data;

    cin >> data;
    node *head = NULL;
    node *tail = NULL;

    while (data != -1)
    {
        node *newnode = new node(data);
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = tail->next;
        }

        cin >> data;
    }
    return head;
}

bool palidrome(node *head)
{
    node *slow = head;
    node *fast = head;
    while (fast != NULL && fast->next != NULL) // Fast == null when list is odd and fast->next ==null list is evem
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    node *prevnode = NULL;
    node *currnode = slow;
    node *nextnode ;
    while (currnode != NULL)
    {
        nextnode = currnode->next;
        currnode->next = prevnode;
        prevnode = currnode;
        currnode = nextnode;
    }
    fast = head;
    while (prevnode != NULL)
    {
        if (fast->data != prevnode->data)
        {
            return false;
        }
        else
        {
            fast = fast->next;
            prevnode = prevnode->next;
        }
    }
    return true;
}

void print(node *head)
{
    while (head != NULL)
    {
        cout << head->data << endl;
        head = head->next;
    }
}
int main()
{
    node *x = takeinput_better();
   
    int c = palidrome(x);
    cout << c;
}