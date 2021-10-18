#include<bits/stdc++.h>
using namespace std;

void dfile() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

// Structure of node //
class node {
public:
	int data;
	node* next; // It is of type node, as the pointer is pointing to the next node.

	// Constructor to take value as input.
	node(int val) {
		data = val;
		next = NULL;
	}
};

/*--------------------------------- Insertion in a list - Start --------------------------------- */

// Insert at Head in list
void insertAtHead(node* &head, int val) {
	node* n = new node(val);
	n->next = head; // Here, head contains the address of head node & we are shifting it to the new node next.
	head = n; // Here, Moved the head pointer to the new node.
}

// Insert at Middle in list at position x
void insertAtMiddle(node* &head, int val, int idx) {
	node* n = new node(val);
	node*temp = head;
	idx--;
	while (idx != 1) {
		temp = temp->next;
		idx--;
	}
	// Here, order is very imp.
	n->next = temp->next;// First, update the next ptr of new node to the next node.
	temp->next = n;// Now we update the temp next ptr with the ptr of new node
}

// Insert at Tail in list
void insertAtTail(node* &head, int val) { // Here, head is taken as reference as we will modify the list.
	node* n = new node(val); // Created a new node n.

	// If our list doesn't contain any value, then the elemnet at first will be our element at tail.
	if (head == NULL)
	{
		head = n;
		return;
	}

	node* temp = head; // New node n,pointing to head.

	// Traversing the list
	while (temp->next != NULL) {
		temp = temp->next;
	}

	temp->next = n;
}
/*--------------------------------- Insertion in a list - End --------------------------------- */

/*--------------------------------- Deletion in a list - Start --------------------------------- */

void deleteHead(node* &head) {

	if (head == NULL)
	{
		return; // If list is empty.
	}

	node* temp = head;

	head = head->next;
	delete temp;
}

void deleteTail(node* &head) {
	node* temp = head;
	node* previousNodeToTemp = head;
	while (temp->next != NULL) {
		previousNodeToTemp = temp;// Here we will keep the track of the previous node
		temp = temp->next;
	}
	previousNodeToTemp->next = NULL;
	delete temp;
}

void deleteMiddle(node* &head, int idx) {
	node* temp = head;
	node* previousNodeToTemp = head; // If you want you can directly initilize it inside the loop.
	while (temp != NULL and idx != 1) {
		previousNodeToTemp = temp;
		temp = temp->next;
		idx--;
	}
	previousNodeToTemp->next = temp->next;
	delete temp;
}
/*--------------------------------- Deletion in a list - End --------------------------------- */


// To display the list
void displayList(node* head) { // Here, head is not taken as reference as we don't want to modify the list.
	node* temp = head;
	while (temp != NULL) {
		cout << temp->data << "->";
		temp = temp->next;
	}
	cout << "NULL" << "\n";
}

// Searching a key in list
bool searchList(node* head, int key) {
	node* temp = head;
	while (temp != NULL) {
		if (temp->data == key) return true;
		temp = temp->next;
	}
	return false;
}

int main()
{
	dfile();
	int n; cin >> n;
	node* head = NULL; // Here, NULL is a NULL pointer who is not assigned any address, the memory location assigned to the reference contains the value 0 .

	// Taking input of list and displaying it
	for (int i = 0; i < n; ++i)
	{	// 4 1 2 3 4

		int val; cin >> val;
		insertAtTail(head, val);
	}
	displayList(head); // 1->2->3->4->NULL


	// Inserting a new node at head.
	insertAtHead(head, 5);
	displayList(head); // 5->1->2->3->4->NULL

	// Insert an element in middle at position x;
	insertAtMiddle(head, 7, 2);
	displayList(head); // 5->7->1->2->3->4->NULL

	// Delete  the first/head node
	deleteHead(head);
	displayList(head);

	// Delete tail node
	deleteTail(head);
	displayList(head);

	//Delete any intermediate Node in List
	deleteMiddle(head, 3);
	displayList(head);

	// 	Searching a key = 3
	if (searchList(head, 3))
	{
		cout << "Key found";
	}
	else {
		cout << "Key not present";
	}
	cout << endl;

	return 0;
}
