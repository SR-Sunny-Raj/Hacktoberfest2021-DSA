
// segregation of even and odd nodes means separating node containing even number and node containing odd numbers
// and modifing the LinkedList to first contain even nodes then odd nodes

import java.util.Scanner;

class LinkedList
{
	Node head; // head of list

	/* Linked list Node*/
	class Node
	{
		int data;
		Node next;
		Node(int d)
		{
			data = d;
			next = null;
		}
	}
    
    // function to segregate even and odd nodes
	void segregateEvenOdd()
	{
		Node end = head;
		Node prev = null;
		Node curr = head;

		while (end.next != null)
			end = end.next;

		Node new_end = end;

		while (curr.data %2 !=0 && curr != end)
		{
			new_end.next = curr;
			curr = curr.next;
			new_end.next.next = null;
			new_end = new_end.next;
		}

		if (curr.data %2 ==0)
		{
			head = curr;
			while (curr != end)
			{
				if (curr.data % 2 == 0)
				{
					prev = curr;
					curr = curr.next;
				}
				else
				{
					prev.next = curr.next;
					curr.next = null;
					new_end.next = curr;
					new_end = curr;
					curr = prev.next;
				}
			}
		}
		else prev = curr;

		if (new_end != end && end.data %2 != 0)
		{
			prev.next = end.next;
			end.next = null;
			new_end.next = end;
		}
	}

	// push a new node to the linked list 
	void push(int new_data)
	{
		Node new_node = new Node(new_data);
		new_node.next = head;
		head = new_node;
	}

	// to print linked list
	void printList()
	{
		Node temp = head;
		while(temp != null)
		{
			System.out.print(temp.data+" ");
			temp = temp.next;
		}
		System.out.println();
	}

	public static void main(String args[])
	{
		LinkedList llist = new LinkedList();
		System.out.println("Enter a whole number to keep pushing to linked list, enter -1 to stop pushing"+"\n");
		Scanner scan=new Scanner(System.in);
		int a;
		a=scan.nextInt();
		while(a>=0){
		    llist.push(a);
		    a=scan.nextInt();
		}
		System.out.println("Origional Linked List");
		llist.printList();

		llist.segregateEvenOdd();

		System.out.println("Modified Linked List");
		llist.printList();
	}
} 
