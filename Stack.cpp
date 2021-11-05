#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int d) : data(d), next(NULL) {}
};
class Stack
{
public:

    Node *head;
    Stack() : head(NULL) {}
    void push(int data)
    {
        if (!head)
        {
            head = new Node(data);
        }
        else
        {
            Node *temp = new Node(data);
            temp->next = head;
            head = temp;
        }
    }
    int top()
    {
        return head->data;
    }
    void pop()
    {
        if (!head)
            return;
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    bool empty()
    {
        return head == NULL ? true : false;
    }

};

void transfer(Stack &s1,Stack &s2,int n)
{
	for (int i = 0; i < n; i++) {

		int temp = s1.top();

				s1.pop();

			s2.push(temp);
	}
}

void RearrangingStack(Stack &s,Stack &s2,int n)
{
	Stack s3;

	while(!s.empty()and !s2.empty())
	{
	    s3.push(s2.top());
	    s2.pop();
	}
	s=s3;

}

int main()
{
	int n ;

	Stack s;

	cout<<"Enter size of stack: ";
	cin>>n;
	int val;
	cout<<"\nEnter 1st stack elements: ";
	for(int i=0;i<n;i++)
    {
        cin>>val;
        s.push(val);
    }
    Stack s2;
    	cout<<"\nEnter 2nd stack elements: ";
	for(int i=0;i<n;i++)
    {
        cin>>val;
        s2.push(val);
    }


	cout<<endl;
	RearrangingStack(s, s2,n);

	for (int i = 0; i < n; i++) {
		cout << s.top() << " ";
		s.pop();
	}
	return 0;
}
