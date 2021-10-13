//Segregate even and odd nodes in a Link List 

//Given a link list of size N, modify the list such that all the even numbers appear 
//before all the odd numbers in the modified list. The order of appearance of numbers within each 
//segregation should be same as that in the original list.

//Example:

// Input: 
// Link List:17 -> 15 -> 8 -> 9 -> 2 -> 4 -> 6 -> NULL
// Output: 8 2 4 6 17 15 9

public class segregateEvenAndOdd {
    public class ListNode {
        int val;
        ListNode next;

        ListNode() {
        }

        ListNode(int val) {
            this.val = val;
        }

        ListNode(int val, ListNode next) {
            this.val = val;
            this.next = next;
        }
    }

    public ListNode segregateEvenOdd(ListNode head) {
        ListNode dummyOdd = new ListNode(-1);
        ListNode dummyEven = new ListNode(-1);
        ListNode odd = dummyOdd;
        ListNode even = dummyEven;

        ListNode curr = head;
        while (curr != null) {
            if (curr.val % 2 != 0) {
                odd.next = curr;
                odd = odd.next;
            } else {
                even.next = curr;
                even = even.next;
            }

            curr = curr.next;
        }

        even.next = dummyOdd.next;
        odd.next = null;

        return dummyEven.next;

    }
}