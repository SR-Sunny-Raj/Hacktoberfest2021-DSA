/*This is the working code for searching the intersection node in an intersected or non-intersected LinkedList.

Data Structure used - Linkedlist 
Reason to use this Data Structure  - 1. It is a linkedlist that we are working on. So switching it to other data structure is useless and increase complexity. Modifying the same linkedlist is more efficient than using arrays etc. which is a continous memory.
Data contained in the structure. - The data can be integer or character. For our understanding we will proceed with integer linkedlist.

Test Cases - (It is always necessary to search as much test cases as possible. This way it is easier to search the pattern that leads us to solution.)

1. 1-2-3-4-5                 2. 1-2-3-4-5      4. 1-2
            \                   6-7-8-9-10      null(emptyLinkedList)
             6-7         
            /               3. 1-2-3           5. 1
         8-9                   4-5                2 

6.1-2-3
        \
         7-8-9     7. 1          8. null
        /              \            null
   4-5-6                2

   Implementations - 
   1. (Naive approach) - Traverse to every Node of LinkedList 1 and compare it with every Node of Linkedlist 2 . The one that matches is the intersected node. 
   Complexity O(n^2)

   2. (average approach) - Traverse both the Linkedlist and count length. Then calculate the difference in length. Further traverse node fro the same length to search the intersected node. The same index is the intersecting node.
   Complexity - counting length O(n) + searching intersection <= O(n) 

   3.(Best approach) - Start traversing both linkedlist. If you reach to the tail of  linkedlist1 then join it to head of linkedlist2 and do the same for linkedlist2. Keep traversing, in second traverse if there is a intersection node u will encounter same index else on condition (no intersection present) it will terminate loop.
   Complexity - if same length (intersection present) < O(n)
              - if same length (intersection not present) = O(n)
              - if varying length (intersection present) =  > O(n) && < O(2n)
              - if varying length (intersection not present) =  O(2n)
              - if single node list or empty list = O(1)

Let us elaborate the 3rd approach.
1. Let we have a linklist 
  1-2-3
        \
         4- 5         intersecting node is 4
        /
     7-6 
2. linkedlist 1 is 1-2-3-4-5 and linkedlist 2 is 7-6-4-5 . Start traversing both linkedlist from head i.e. 1 and 7
    traverse count  linkedlist1  linkedlist2
3.       1               1            7
          2               2           6
          3               3           4
          4               4           5
          (now linkedlist2 reached null so we will join tail of linkedlist2 i.e. 5 node to head of likedlist1 i.e. 1 )

4. It will now look 
     - - - - - - -- 
    /               \
    1 - 2- 3         | 
            \       / 
              4-5--
            /
        7-6
5. Again start traversing from where we left it above we were in linkedlist1 (node 4) and linkedlist 2 (node5) note there is no null after 5 now.
    traverse count  linkedlist1  linkedlist2
          5             5             1
          (now this time linkedlist2 reached the end that is 5(as u stored the node when u reached earlier in traverseNo 4.) So now we will join the node 5 to linkedlist2 haed i.e. 7 )
    
6. It will look

                 
    1 - 2- 3         
            \       
              4-5-
            /      \ 
        7-6         \
        \           /
         - - - - - - 
6. again start traversing(this time u will get the intesecting node)
    traverse count  linkedlist1  linkedlist2
          6              7            2
          7              6            3
          8              4            4
          Bingo..... we got the intersecting node in complexity less than complete O(2n)

 Watch that if u try this in test case no. 2 will be done in O(n) on giving condition
                             test case no. 3 will be done in O(2n). as it has no intersection. on reachong end node loop will terminate.
                             test case no. 4 will not run any loop as linkedlist2 is empty
                             test case no. 5 will run same as testcase 2.
                             test case no. 6 will be done in Complexity < O(n) as length is same, intersection present and we dont have to join tail of one linkedlist to head of other.(this is the difference between approach 2 and approach 3)
                             test case no. 7 will run same as 6.
                             test case no. 8 will not execute loop O(1).
     Try to search more test cases for practice.


Implementation - 

 This is the ListNode class definition
 */

class ListNode {
	int data;
	ListNode next;

	ListNode(int data) {
		this.data = data;
		this.next = null;
	}
}

//here Listnode A is head of linkedlist 1 and listnode B is haed of linkedlist 2
//traverse1 is traversing linkedlist1 and traverse2 for linkedlist2
//temp stores the last node that has null in next.

class IntersectionNodeInLinkedlist {
	ListNode getIntersectionNode(ListNode A, ListNode B) {
		
	if(A != null && B != null)
	{
		ListNode traverse1 = A;
		ListNode traverse2 = B;
		ListNode temp = null;
		
		while(true)
		{
			if(traverse1 == traverse2)
			{
				return traverse1;
			}
			else
			{
				if(traverse1.next != null)
				{
					if(temp == null)
					{
						traverse1 = traverse1.next;
					}
					else{
						if(temp == traverse1)
							traverse1.next = B;
						traverse1 = traverse1.next;
					}
				}
				else{
					if(temp == null)
					{
						traverse1.next = B;
						temp = traverse1;
						traverse1 = traverse1.next;
					}
					else{
						return null;
					}
				}
				if(traverse2.next != null)
				{
					if(temp == null)
					{
						traverse2 = traverse2.next;
					}
					else{
						if(temp == traverse2)
							traverse2.next = A;
						traverse2 = traverse2.next;
					}
				}
				else{
					if(temp == null)
					{
						traverse2.next = A;
						temp = traverse2;
						traverse2 = traverse2.next;
					}
					else{
						return null;
					}
				}
			}
		}
			
	}
		
		return null;
	}
}

// The output of the code is the intersecting node.

// Written by - Diksha Soni on 10-oct-2022 for the hacktoberfest Pull request.