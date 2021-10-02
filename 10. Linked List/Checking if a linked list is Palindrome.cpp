#include<bits/stdc++.h>
using namespace std;

class Node {
public:
		int val;
		Node(int d){
			val = d;
		}
		Node *next;
};

// Function to check if the linked list
// is palindrome or not
Node* reverseLL(Node* head) {
	Node* p1, *p2;
	if (head == nullptr) return head;
	
	p1 = head;
	p2 = p1->next;
	while (p2) {
		Node *p3 = p2->next;
		p2->next = p1;
		p1 = p2;
		p2 = p3;
	}
	head->next = nullptr;
	head = p1;
	
	return head;
}
    
bool isPalindrome(Node* head) {
	if (head == nullptr) 
		return head;
	
	Node *slow, *fast;
	slow = fast = head;
	
	// Finding the middle element of the LL
	while (fast && fast->next) {
		fast = fast->next->next;
		slow = slow->next;
	}
	
	if (!fast) {
		slow = reverseLL(slow);
		// After the call of above method an eg. 
		// LL(with even number of elements) will look like
		// 1 -> 2 -> 2 <- 1
		// h              s  
	} else {
		slow = slow->next;
		slow = reverseLL(slow);
		// After the call of above method an eg. 
		// LL(with odd number of elements) will look like
		// 1 -> 2 -> 3 -> 2 <- 1
		// h                   s 
	}
	
	Node *n1 = head;
	Node *n2 = slow;
	// Traverse till the n2 is null
	while (n2) {
		if (n1->val != n2->val) {
			return false;
		}
		n2 = n2->next;
		n1 = n1->next;
	}
	
	return true;
}
// Driver Code
int main(){

	// Addition of linked list
	Node one = Node(1);
	Node two = Node(2);
	Node three = Node(3);
	Node four = Node(2);
	Node five = Node(1);

	// Initialize the next pointer
	// of every current pointer
	five.next = nullptr;
	one.next = &two;
	two.next = &three;
	three.next = &four;
	four.next = &five;
	Node* head = &one;

	
	// Call function to check palindrome or not
	bool res = isPalindrome(head);

	cout << (res ? "LL is Palindrone\n" : "LL is not Palindrone\n"); 

	return 0;
}