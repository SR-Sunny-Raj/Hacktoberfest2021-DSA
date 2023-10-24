// cpp code for copying a list with random pointer


method1- Time complexity: O(n), Space Complexity: O(n)
  
// code
#include <bits/stdc++.h>
using namespace std;
 

struct Node
{
    int data;
    Node* next;
    Node* random;
 
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
        this->random = nullptr;
    }
};
 
void traverse(Node* head)
{
    if (head == nullptr)
    {
        cout << "null" << endl;
        return;
    }
    if (head->random) {
        cout << head->data << "(" << head->random->data << ") —> ";
    }
    else {
        cout << head->data << "(" << "X" << ") —> ";
    }
 
    traverse(head->next);
}
 

void updateRandomPointers(Node* head, unordered_map<Node*, Node*> &map)
{
    if (map[head] == nullptr) {
        return;
    }
    map[head]->random = map[head->random];
    updateRandomPointers(head->next, map);
}
 
 
Node* cloneLinkedList(Node* head, unordered_map<Node*, Node*> &map)
{
    if (head == nullptr) {
        return nullptr;
    }
    map[head] = new Node(head->data);
    map[head]->next = cloneLinkedList(head->next, map);
    
    
    return map[head];
}
 
Node* cloneLinkedList(Node* head)
{
    unordered_map<Node*, Node*> map;
    cloneLinkedList(head, map);
    updateRandomPointers(head, map);
    
    
    return map[head];
}
 
int main()
{
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->random = head->next->next->next;
    head->next->next->random = head->next;
 
    cout << "Original Linked List:\n";
    traverse(head);
 
    Node* clone = cloneLinkedList(head);
 
    cout << "\nCloned Linked List:\n";
    traverse(clone);
 
    return 0;
}





// method2: Time complexity: O(n), Space Complexity: O(1)

// code

#include <bits/stdc++.h>
using namespace std;
 
struct Node
{
    int data;
    Node* next;
    Node* random;
 
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
        this->random = nullptr;
    }
 
    Node() {}
};
 
void traverse(Node* head)
{
    while (head != nullptr)
    {
        if (head->random) {
            cout << head->data << "(" << head->random->data << ") —> ";
        }
        else {
            cout << head->data << "(" << "X" << ") —> ";
        }
        head = head->next;
    }
    cout << "null" << endl;
}
 
Node* cloneLinkedList(Node* head)
{
 
    Node* curr = head;
    while (curr != nullptr)
    {
        Node* next = curr->next;
        Node* dup = new Node(curr->data);
        curr->next = dup;
        dup->next = next;
        curr = next;
    }
 
    curr = head;
    while (curr != nullptr)
    {
        if (curr->random != nullptr) {
            (curr->next)->random = (curr->random)->next;
        }
        curr = (curr->next)->next;
    }
 
    Node dummy;
    Node* tail = &dummy;
    curr = head;
    while (curr != nullptr)
    {
        Node* next = curr->next->next;
        Node* dup = curr->next;
        tail->next = dup;
        tail = dup;
        curr->next = next;
        curr = next;
    }
 
    return dummy.next;
}
 
int main()
{
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
 
    head->random = head->next->next->next;
    head->next->next->random = head->next;
 
    cout << "Original linked list:\n";
    traverse(head);
 
    Node* clone = cloneLinkedList(head);
 
    cout << "\nCloned linked list:\n";
    traverse(clone);
 
    return 0;
}
