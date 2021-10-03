/**
 * You are given two linked lists: list1 and list2 of sizes n and m
 * respectively.
 * 
 * Remove list1's nodes from the ath node to the bth node, and put list2 in
 * their place.
 * 
 * Definition for singly-linked list. public class ListNode { int val; ListNode
 * next; ListNode() {} ListNode(int val) { this.val = val; } ListNode(int val,
 * ListNode next) { this.val = val; this.next = next; } }
 */

class Solution {
  public ListNode mergeInBetween(ListNode list1, int a, int b, ListNode list2) {
    ListNode t1 = list1;
    for (int i = 0; i < a - 1; i++) {
      t1 = t1.next;
    }

    ListNode temp = t1.next;
    t1.next = list2;
    for (int i = 0; i < (b - a); i++) {
      temp = temp.next;
    }
    while (t1.next != null) {
      t1 = t1.next;
    }
    t1.next = temp.next;
    return list1;
  }
}