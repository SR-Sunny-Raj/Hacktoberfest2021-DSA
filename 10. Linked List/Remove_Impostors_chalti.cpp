/**
 * rmove_imposters_chalti.cpp
 * 
 * description :-
 * 
 * We will be deleting M nodes after N number of nodes, so we can esily find it by using loops. 
 * so for that we will be taking a  while loop which will traverse the
 * whole linkedlist, and make :- first node's next will be the M+1 th nodes address, and do this for N times
 * 
 * Time complexity : O(n)
 * Space complexity : O(n)
 * 
 *  @author[chaltidutta](https://github.com/chaltidutta)
 * **/

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void removeImpst(struct Node *head, int M, int N)
{
    Node *temp = head, *aux;
    while (temp) //start traversing in the linkedlist
    {
        int pos = M - 1;
        int cov = N;
        while (temp and pos--) //skipping
            temp = temp->next;
        if (temp == NULL)
            return;
        aux = temp->next;
        while (aux and cov--)
            aux = aux->next; 
        temp->next = aux;
        temp = temp->next;
    }
}

int main()
{

    //making the linked list

    int n; //length of the linked list
    cin >> n;
    int M, N;
    cin >> M >> N;

    //taking element input of the linked list
    if (n > 0)
    {
        int data; //length of the ll
        cin >> data;
        Node *head = new Node(data);
        Node *tail = head;

        for (int i = n; i > 1; i--)
        {
            cin >> data;
            tail->next = new Node(data);
            tail = tail->next;
        }

        removeImpst(head, M, N);
        while (head != NULL)
        {
            cout << head->data << " ";
            head = head->next;
        }
    }
    else
    {
        cout << "Null Linked List" << endl; //if the linked list is null
    }

    return 0;
}
