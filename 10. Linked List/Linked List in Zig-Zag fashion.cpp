#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

void print(Node *root)
{
	Node *temp = root;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}
 

 // } Driver Code Ends
/*

The structure of linked list is the following
struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};
*/

class Solution
{
    public:
    Node *zigZag(Node* head)
    {
        if (head == NULL || head->next == NULL) {
        return head;
    }
 
    // to store new head
    Node* res = NULL;
 
    // to traverse linked list
    Node* curr = head;
 
    // to store previous node of current node
    Node* prev = NULL;
 
    // to store new next node of current node
    Node* next;
 
    // to check if current element should
    // be less than or greater than.
    // ind = 0 --> less than
    // ind = 1 --> greater than
    int ind = 0;
 
    while (curr->next) {
 
        // If elements are not in zigzag fashion
        // swap them.
        if ((ind == 0 && curr->data > curr->next->data)
            || (ind == 1 && curr->data < curr->next->data)) {
 
            if (res == NULL)
                res = curr->next;
 
            // Store new next element of current
            // node
            next = curr->next->next;
 
            // Previous node of current node will
            // now point to next node of current node
            if (prev)
                prev->next = curr->next;
 
            // Change next pointers of both
            // adjacent nodes
            curr->next->next = curr;
            curr->next = next;
 
            // Change previous pointer.
            if (prev)
                prev = prev->next;
            else
                prev = res;
        }
 
        // If already in zig zag form, then move
        // to next element.
        else {
            if (res == NULL) {
                res = curr;
            }
 
            prev = curr;
            curr = curr->next;
        }
 
        // Update info whether next element should
        // be less than or greater than.
        ind = 1 - ind;
    }
 
    return res;
    }
};

// { Driver Code Starts.


int main() {
	// your code goes here
	int T;
	cin>>T;
	
	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;
 
		for(int i=0;i<K;i++){
		int data;
		cin>>data;
			if(head==NULL)
			head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp=temp->next;
			}
		}
		Solution ob;
		Node *ans = ob.zigZag(head);
		print(ans);
		cout<<endl;
	}
	return 0;
}  // } Driver Code Ends