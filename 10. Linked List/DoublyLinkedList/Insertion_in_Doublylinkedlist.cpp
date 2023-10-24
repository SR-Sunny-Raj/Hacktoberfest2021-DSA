#include <iostream>
using namespace std;

class dl
{
    struct node
    {
        struct node *prev;
        int data;
        struct node *next;
    };
    struct node *head;
    struct node *last;

public:
    dl()
    {
        head = NULL;
    }
    void createlist();
    void show();
    void insert_beg();
    void insert_end();
    void insert_pos();
    void insert_after();
    void insert_before();
};

int main()
{

    dl l1;

    l1.createlist();
    l1.show();
    
    // l1.insert_beg();
    // l1.insert_end();
    // l1.insert_pos();
    // l1.insert_after();
    l1.insert_before();
    l1.show();
    
}

void dl::show()
{
    struct node *ptr;
    ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}
void dl::createlist()
{
     cout << "enter the values, enter -1 to print the list ";
    int num;
    cin >> num;
    while (num > 0)
    {
        node *nn = new node;
        if (head == NULL)
        {
            nn->prev = NULL;
            nn->data = num;
            nn->next = NULL;
            head = nn;
            last = nn;
        }
        else
        {
            nn->data = num;
            nn->next = NULL;
            nn->prev = last;

            last->next = nn;
            last = nn;
        }
        cin >> num;
    }
}
void dl::insert_beg()
{
    node *nn = new node;
    int val;
    cout << endl
         << "insert value here to add in the beginning "
         << " ";
    cin >> val;
    nn->data = val;
    nn->next = head;
    head->next->prev = nn;
    head = nn;
}
void dl::insert_end()
{
    node *nn = new node;
    int val;
    cout << endl
         << "insert value here to add at the end "
         << " ";
    cin >> val;
    nn->data = val;
    nn->prev = last;
    last->prev->next = nn;
    nn->next = NULL;
    last = nn;
}
void dl::insert_pos()
{
    node *nn = new node;
    node *ptr = new node;
    ptr = head;
    // nn = head;
    int val, pos;
    cout << endl
         << "insert value here "
         << " ";
    cin >> val;
    cout << endl
         << "insert the position here ";
    cin >> pos;
    for (int i = 1; i < pos - 1; i++)
    {
        ptr = ptr->next;
    }
    nn->data = val;
    nn->prev = ptr;
    nn->next = ptr->next;
    ptr->next->prev = nn;
    ptr->next = nn;
}

void dl::insert_after()
{
    node *nn = new node;
    node *ptr = new node;
    ptr = head;
    // nn = head;
    int val, pos;
    cout << endl
         << "insert value here to add after the specific position "
         << " ";
    cin >> val;
    cout << endl
         << "insert the position here ";
    cin >> pos;
    for (int i = 1; i < pos; i++)
    {
        ptr = ptr->next;
    }
    nn->data = val;
    nn->prev = ptr;
    nn->next = ptr->next;
    ptr->next->prev = nn;
    ptr->next = nn;
}
void dl::insert_before()
{
    node *nn = new node;
    node *ptr = new node;
    ptr = head;
    // nn = head;
    int val, pos;
    cout << endl
         << "insert value here to add before the specific position "
         << " ";
    cin >> val;
    cout << endl
         << "insert the position here ";
    cin >> pos;
    for (int i = 1; i < pos -2; i++)
    {
        ptr = ptr->next;
    }
    nn->data = val;
    nn->prev = ptr;
    nn->next = ptr->next;
    ptr->next->prev = nn;
    ptr->next = nn;
}