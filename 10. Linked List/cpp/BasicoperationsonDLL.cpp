#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *prev;
    struct node *next;
    node(int x)
    {
        data = x;
        prev = NULL;
        next = NULL;
    }
} *head = NULL, *tail = NULL;
void create()
{
    int n;
    cout << "Enter number of nodes. ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cout << "Enter the value of element " << i + 1 << " ";
        cin >> x;
        node *cur = new node(x);
        if (head == NULL)
        {
            head = tail = cur;
        }
        else
        {
            cur->prev = tail;
            tail->next = cur;
            tail = cur;
        }
    }
}
int cnoe(node *head)
{
    int count = 0;
    node *p = head;
    while (p != NULL)
    {
        count++;
        p = p->next;
    }
    cout << endl
         << "No. of elements in linked list. " << count << endl;
    return count;
}
int size(node *head)
{
    int count = 0;
    for (; head != NULL; head = head->next)
    {
        count++;
    }
    //cout << count;
    return count;
}
void display()
{
    cout << "Displaying link list" << endl;
    struct node *ptr = head;
    for (ptr = head; ptr != NULL; ptr = ptr->next)
    {
        cout << ptr->data << " ";
    }
    cout << endl;
}
void insert_beg()
{
    int x;
    cout << "\nEnter the value to insert at beginning. ";
    cin >> x;
    node *cur = new node(x);
    if (head == NULL)
    {
        head = tail = cur;
    }
    else
    {
        cur->next = head;
        head->prev = cur;
        head = cur;
    }
    display();
}
void insert_end()
{
    int x;
    cout << "\nEnter the value to insert at end. ";
    cin >> x;
    node *cur = new node(x);
    if (head == NULL)
    {
        head = tail = cur;
    }
    else
    {
        cur->prev = tail;
        tail->next = cur;
        tail = cur;
    }
    display();
}
void insert_pos()
{
    int pos, ele;
    cout << endl;
    cout << "Enter the position for insertion: ";
    cin >> pos;
    cout << " Enter the element: ";
    cin >> ele;
    node *temp = new node(ele);
    node *ptr = head;
    if (pos < 1)
    {
        cout << "INVALID POSITION.";
    }
    if (pos == 1)
    {
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
    else if (pos >= size(head) + 1)
    {
        tail->next = temp;
        temp->prev = NULL;
        tail = temp;
    }
    else
    {
        for (int i = 0; i < pos - 2; i++)
        {
            ptr = ptr->next;
        }

        temp->prev = ptr;
        temp->next = ptr->next;
        ptr->next->prev = temp;
        ptr->next = temp;
    }
    display();
}
int search()
{
    int val, res;
    cout << "Enter the value to search. ";
    cin >> val;
    node *ptr = head;
    int pos = 1;
    for (ptr = head; ptr != NULL; ptr = ptr->next)
    {
        if (ptr->data == val)
        {
            cout << "Element fount at " << pos;
            return 0;
        }
        else
        {
            pos++;
            res = 1;
        }
    }
    // else
    cout << "Element not found.";
    return -1;
}
void del_beg()
{
    node *ptr = head;
    head = head->next;
    delete ptr;
    cout << "\nAFTER DELETING THE BEGINNING\n";
    display();
    // cout << endl;
    //  cout << tail->data << endl;

    //  cout << tail->prev->data << endl;
}
void del_end()
{
    node *ptr = tail;
    tail = tail->prev;
    tail->next = NULL;
    delete ptr;
    cout << "\nAFTER DELETING THE END\n";
    display();
}
void del_pos()
{
    int pos, i;
    cout << "Enter the position of the value you want to delete. ";
    cin >> pos;
    node *ptr;
    for (i = 0, ptr = head; i < pos - 1 && ptr != NULL; i++, ptr = ptr->next)
        ;
    //cout << ptr->data;
    if (ptr->next == NULL)
    {
        del_end();
    }
    else
    {
        ptr->next->prev = ptr->prev;
        ptr->prev->next = ptr->next;
        delete ptr;
        cout << "\nAFTER DELETION. \n";
        display();
    }
}

int main()
{
    int a;
    char ans;
    cout << "DOUBLE LINK LIST" << endl
         << "1.Create a doubly link list." << endl
         << "2.Display the doubly link list." << endl
         << "3.Insert at the beginning of doubly link list." << endl
         << "4.Insert at the end of doubly link list." << endl
         << "5.Insert at a position of doubly link list." << endl
         << "6.Count the number of elements." << endl
         << "7.Delete element from the beginning." << endl
         << "8.Delete element from the end." << endl
         << "9.Delete element from a provided position." << endl
         << "10.EXIT " << endl;
    while (ans != 'n')
    {
        cout << "Enter an option to continue with.\t";
        cin >> a;

        switch (a)
        {
        case 1:
            create();
            break;
        case 2:
            display();
            break;
        case 3:
            insert_beg();
            break;
        case 4:
            insert_end();
            break;
        case 5:
            insert_pos();
            break;
        case 6:
            cnoe(head);
            break;
        case 7:
            del_beg();
            break;
        case 8:
            del_end();
            break;
        case 9:
            del_pos();
            break;
        case 10:
            return 0;
            break;
        default:
            "INVALID ENTRY. TRY AGAIN";
        }
        cout << "Do you want to continue enter 'y' or 'n' ";
        cin.ignore();
        cin >> ans;
    }
    return 0;
}
