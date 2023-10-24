
#include <bits/stdc++.h>
using namespace std;

struct Node {
	int key;
	struct Node* next;
};

Node* newNode(int key)
{
	Node* temp = new Node;
	temp->key = key;
	temp->next = NULL;
	return temp;
}

void printList(Node* head)
{
	while (head != NULL) {
		cout << head->key << " ";
		head = head->next;
	}
	cout << endl;
}

int distance(Node* first, Node* last)
{
	int counter = 0;

	Node* curr;
	curr = first;

	while (curr != last) {
		counter += 1;
		curr = curr->next;
	}

	return counter + 1;
}

bool detectLoop(Node* head)
{

	Node* temp = new Node;

	Node *first, *last;

	first = head;
	last = head;

	int current_length = 0;

	int prev_length = -1;

	while (current_length > prev_length && last != NULL) {
	
		prev_length = current_length;
	
		current_length = distance(first, last);
		
		last = last->next;
	}
	
	if (last == NULL) {
		return false;
	}
	else {
		return true;
	}
}
int main()
{
	Node* head = newNode(1);
	head->next = newNode(2);
	head->next->next = newNode(3);
	head->next->next->next = newNode(4);
	head->next->next->next->next = newNode(5);

	head->next->next->next->next->next = head->next->next;

	bool found = detectLoop(head);
	if (found)
		cout << "Loop Found";
	else
		cout << "No Loop Found";

	return 0;
}
